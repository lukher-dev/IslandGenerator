#include "islandgenerator.h"
#include "PerlinNoise.h"
#include<string.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>

IslandGenerator::IslandGenerator()
{
    points_string = "[0.3,0.2],[0.1,0.9],[0.9,0.9],[0.6,0.7],[0.8,0.1]";
    land_noise = (float)0.32;
    land_height = (float)0.06;
    seabed_noise = (float)0.1;
    seabed_height = (float)0.17;
    water_height = (float)0.0;
    frequency = (float)3.6;
    resolution = 40;
    octaves = (float)0.43;
    scroll = (float)2.47;
    roughness = (float)0.14;
    roughness_frequency = (float)7;
    srand((unsigned) time(0));
    seed = rand();
    name = "test";
}

void IslandGenerator::saveToFile() {
  std::ofstream myfile (name+".txt");
      for (int i = 0; i < resolution; i += 1) {
          for (int j = 0; j < resolution; j += 1) {
              myfile << height_map[i][j]<< " ";
          }
          myfile << "\n";
      }
    myfile.close();

    std::ofstream jsonFile (name+"_params.json");
    jsonFile << "{\n";
    jsonFile << "points_string" << ": " << points_string << "\n";
    jsonFile << "land_noise" << ": " << land_noise << ",\n";
    jsonFile << "land_height" << ": " << land_height << ",\n";
    jsonFile << "seabed_noise" << ": " << seabed_noise << ",\n";
    jsonFile << "seabed_height" << ": " << seabed_height << ",\n";
    jsonFile << "water_height" << ": " << water_height << ",\n";
    jsonFile << "frequency" << ": " << frequency << ",\n";
    jsonFile << "resolution" << ": " << resolution << ",\n";
    jsonFile << "octaves" << ": " << octaves << ",\n";
    jsonFile << "scroll" << ": " << scroll << ",\n";
    jsonFile << "roughness" << ": " << roughness << ",\n";
    jsonFile << "roughness_frequency" << ": " << roughness_frequency << ",\n";
    jsonFile << "seed" << ": " << seed << ",\n";
    jsonFile << "}\n";
    jsonFile.close();
}

std::vector<std::vector<float>> IslandGenerator::generatePerlinMatrix() {
    PerlinNoise pn(seed);
    std::vector<std::vector<float>> perlinMatrix(resolution);
    for (int i = 0; i < resolution; i += 1) {
        perlinMatrix[i].resize(resolution, 0);
        for (int j = 0; j < resolution; j += 1) {
            double x = (double)j / ((double)resolution);
            double y = (double)i / ((double)resolution);
            perlinMatrix[i][j] =
                    (float)(pn.noise(frequency * x, frequency * y, scroll)*(1-octaves) +
                    octaves*(pn.noise(frequency* 2 * x, frequency* 2 * y, scroll)/2.0 +
                             pn.noise(frequency* 4 * x, frequency* 4 * y, scroll)/4.0 +
                             pn.noise(frequency* 8 * x, frequency* 8 * y, scroll)/8.0 +
                             pn.noise(frequency* 16 * x, frequency* 16 * y, scroll)/16.0 +
                             pn.noise(frequency* 32 * x, frequency* 32 * y, scroll)/32.0 +
                             pn.noise(frequency* 64 * x, frequency* 64 * y, scroll)/64.0));
        }
    }
    float min=perlinMatrix[0][0];
    float max=perlinMatrix[0][0];
    for (int i = 0; i < resolution; i += 1) {
        float temp_min = *std::min_element(perlinMatrix[i].begin(), perlinMatrix[i].end());
        if (temp_min<min) min = temp_min;
        float temp_max = *std::max_element(perlinMatrix[i].begin(), perlinMatrix[i].end());
        if (temp_max>max) max = temp_max;
    }
    for (int i = 0; i < resolution; i += 1) {
        for (int j = 0; j < resolution; j += 1) {
            perlinMatrix[i][j] = (perlinMatrix[i][j]-min)/(max-min);
        }
    }
    return perlinMatrix;
}

std::vector<std::vector<float>> IslandGenerator::generateHeightMap() {
    std::vector<std::vector<float>> height_map(resolution);
    for (int i = 0; i < resolution; i++)
        height_map[i].resize(resolution, water_height);
    return height_map;
}

std::vector<std::vector<float>> IslandGenerator::plotLine(std::vector<std::vector<float>> heightMap,std::vector<std::vector<float>> perlinMatrix, float fixed_x0, float fixed_y0, float fixed_x1, float fixed_y1) {
    PerlinNoise pn(seed);
    float range = 1 - land_height;

    int x0, y0, x1, y1;
    x0 = (int)floor(fixed_x0*(resolution-3))+1;
    y0 = (int)floor(fixed_y0*(resolution-3))+1;
    x1 =(int)floor(fixed_x1*(resolution-3))+1;
    y1 = (int)floor(fixed_y1*(resolution-3))+1;

    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;  /* error value e_xy */
    while (true) {
        double x = (double)x0 / ((double)resolution);
        double y = (double)y0 / ((double)resolution);
        heightMap[x0][y0] = (float)(land_noise*(perlinMatrix[x0][y0]-0.5)*range) + land_height/2;
        int splash = (int)abs(roughness*resolution*(pn.noise(roughness_frequency * x, roughness_frequency * y, scroll)-0.5));
        if(splash<0)splash=0;
        for(int i = -splash; i<splash; i++){
            if(y0+i>0 && y0+i<(int)heightMap[0].size()-1)
                 heightMap[x0][y0+i] = (float)((land_noise*(perlinMatrix[x0][y0+i]-0.5)*range) + land_height/2.0);
            if(x0+i>0 && x0+i<(int)heightMap.size()-1)
                 heightMap[x0+i][y0] = (float)((land_noise*(perlinMatrix[x0+i][y0]-0.5)*range) + land_height/2.0);
            if(y0+i>0 && y0+i<(int)heightMap[0].size()-1 && x0+i>0 && x0+i<(int)heightMap.size()-1)
                heightMap[x0+i][y0+i] = (float)((land_noise*(perlinMatrix[x0+i][y0+i]-0.5)*range) + land_height/2.0);
            if(y0-i>0 && y0-i<(int)heightMap[0].size()-1 && x0-i>0 && x0-i<(int)heightMap.size()-1)
                heightMap[x0-i][y0-i] = (float)((land_noise*(perlinMatrix[x0-i][y0-i]-0.5)*range) + land_height/2.0);
        }
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
    return heightMap;
}

std::vector<std::vector<float>>  IslandGenerator::plotPolygon(std::vector<std::vector<float>> heightMap,std::vector<std::vector<float>> perlinMatrix, std::vector<std::vector<float>> points) {
    if (points.size() > 2) {
        for (int i = 0; i < (int)points.size() - 1; i++) {
            heightMap = plotLine(heightMap,perlinMatrix, points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
        }
        heightMap = plotLine(heightMap,perlinMatrix, points[points.size() - 1][0], points[points.size() - 1][1], points[0][0], points[0][1]);
    }
    return heightMap;
}

void IslandGenerator::spawnWater(std::vector<std::vector<float>>& heightMap, std::vector<std::vector<float>>& perlinMatrix, int i, int j) {
    PerlinNoise pn(seed);
    float range = 1 - seabed_height;
    heightMap[i][j] = (float)((seabed_noise*2.0*(perlinMatrix[i][j]-0.5)* range) - seabed_height);
    if (i - 1 >= 0)
    {
        if(heightMap[i - 1][j] == water_height)
            spawnWater(heightMap,perlinMatrix, i - 1, j);
        if(heightMap[i - 1][j] > water_height)
            heightMap[i][j] = heightMap[i][j]/2;
    }
    if (j - 1 >= 0)
    {
        if(heightMap[i][j - 1] == water_height)
            spawnWater(heightMap,perlinMatrix, i, j - 1);
        if(heightMap[i][j - 1] > water_height)
            heightMap[i][j] = heightMap[i][j]/2;
    }
    if (i + 1 < (int)heightMap.size())
    {
        if(heightMap[i + 1][j] == water_height)
            spawnWater(heightMap,perlinMatrix, i + 1, j);
        if(heightMap[i + 1][j] > water_height)
            heightMap[i][j] = heightMap[i][j]/2;
    }
    if (j + 1 < (int)heightMap[0].size())
    {
        if(heightMap[i][j + 1] == water_height)
            spawnWater(heightMap,perlinMatrix, i, j + 1);
        if(heightMap[i][j + 1] > water_height)
            heightMap[i][j] = heightMap[i][j]/2;
    }
}

void IslandGenerator::loadPoints(){
    std::vector<std::vector<float>> new_points;
    float point_x, point_y;
    size_t pos = 0;
    points_string.erase(std::remove(points_string.begin(), points_string.end(), '['), points_string.end());
    points_string.erase(std::remove(points_string.begin(), points_string.end(), ']'), points_string.end());
    std::string temp_string = points_string;
    std::string token;
    int i =0;
    while ((pos = temp_string.find(',')) != std::string::npos) {
        token = temp_string.substr(0, pos);
        if(i==0){
            point_x = std::stof(token);
        }else{
            point_y = std::stof(token);
        }
        temp_string.erase(0, pos + 1);
        i++;
        if(i==2){
            new_points.push_back(std::vector<float>({ point_x, point_y }));
            i=0;
        }
    }

    if(i==0){
        point_x = std::stof(temp_string);
    }else{
        point_y = std::stof(temp_string);
    }
    i++;
    if(i==2){
        new_points.push_back(std::vector<float>({ point_x, point_y }));
    }

    points = new_points;
}

void IslandGenerator::raiseLand(std::vector<std::vector<float>>& heightMap, std::vector<std::vector<float>>& perlinMatrix) {
    float range = 1 - land_height;
    for (int i = 0; i < resolution; i += 1) {
        for (int j = 0; j < resolution; j += 1) {
            if (heightMap[i][j] == water_height)heightMap[i][j] = float((land_noise*2*(perlinMatrix[i][j]-0.5)* range) + land_height);
        }
    }
}

void IslandGenerator::generateIsland() {
    loadPoints();
    perlinMatrix = generatePerlinMatrix();
    height_map = plotPolygon(generateHeightMap(), perlinMatrix, points);
    spawnWater(height_map,perlinMatrix, 0, 0);
    raiseLand(height_map, perlinMatrix);
}
