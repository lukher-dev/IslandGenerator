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
	srand((unsigned)time(0));
	seed = rand();
	name = "output";
}

void IslandGenerator::saveToFile() {
	std::ofstream myfile(name + ".txt");
	for (int i = 0; i < resolution; i += 1) {
		for (int j = 0; j < resolution; j += 1) {
			myfile << height_map[i][j] << " ";
		}
		myfile << "\n";
	}
	myfile.close();

	std::ofstream jsonFile(name + "_params.json");
	jsonFile << "{\n";
	jsonFile << "\"points_string\"" << ": \"" << points_string << "\",\n";
	jsonFile << "\"land_noise\"" << ": \"" << land_noise << "\",\n";
	jsonFile << "\"land_height\"" << ": \"" << land_height << "\",\n";
	jsonFile << "\"seabed_noise\"" << ": \"" << seabed_noise << "\",\n";
	jsonFile << "\"seabed_height\"" << ": \"" << seabed_height << "\",\n";
	jsonFile << "\"water_height\"" << ": \"" << water_height << "\",\n";
	jsonFile << "\"frequency\"" << ": \"" << frequency << "\",\n";
	jsonFile << "\"resolution\"" << ": \"" << resolution << "\",\n";
	jsonFile << "\"octaves\"" << ": \"" << octaves << "\",\n";
	jsonFile << "\"scroll\"" << ": \"" << scroll << "\",\n";
	jsonFile << "\"roughness\"" << ": \"" << roughness << "\",\n";
	jsonFile << "\"roughness_frequency\"" << ": \"" << roughness_frequency << "\",\n";
	jsonFile << "\"seed\"" << ": \"" << seed << "\"\n";
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
				(float)(pn.noise(frequency * x, frequency * y, scroll) * (1 - octaves) +
					octaves * (pn.noise(frequency * 2 * x, frequency * 2 * y, scroll) / 2.0 +
						pn.noise(frequency * 4 * x, frequency * 4 * y, scroll) / 4.0 +
						pn.noise(frequency * 8 * x, frequency * 8 * y, scroll) / 8.0 +
						pn.noise(frequency * 16 * x, frequency * 16 * y, scroll) / 16.0 +
						pn.noise(frequency * 32 * x, frequency * 32 * y, scroll) / 32.0 +
						pn.noise(frequency * 64 * x, frequency * 64 * y, scroll) / 64.0));
		}
	}
	float min = perlinMatrix[0][0];
	float max = perlinMatrix[0][0];
	for (int i = 0; i < resolution; i += 1) {
		float temp_min = *std::min_element(perlinMatrix[i].begin(), perlinMatrix[i].end());
		if (temp_min < min) min = temp_min;
		float temp_max = *std::max_element(perlinMatrix[i].begin(), perlinMatrix[i].end());
		if (temp_max > max) max = temp_max;
	}
	for (int i = 0; i < resolution; i += 1) {
		for (int j = 0; j < resolution; j += 1) {
			perlinMatrix[i][j] = (perlinMatrix[i][j] - min) / (max - min);
		}
	}
	return perlinMatrix;
}

std::vector<std::vector<float>> IslandGenerator::generateHeightMap() {
    float range = 1 - seabed_height;
	std::vector<std::vector<float>> height_map(resolution);
    for (int i = 0; i < resolution; i++){
        height_map[i].resize(resolution, water_height);
            for (int j = 0; j < resolution; j++)
                height_map[i][j] = (float)((seabed_noise * 2.0 * (perlinMatrix[i][j] - 0.5) * range) - seabed_height);
    }
	return height_map;
}

std::vector<std::vector<float>> IslandGenerator::plotPolygon() {
    float range = 1 - land_height;
    PerlinNoise pn(seed);
	std::vector<int> nodeX(resolution);
	int  nodes, pixelX, pixelY, i, j, swap;
	int polyCorners = points.size();
	std::vector<std::vector<float>> height_map = generateHeightMap();

	std::vector<std::vector<float>> points_processed(polyCorners);

	for (i = 0; i < polyCorners; i++) {
		points_processed[i].push_back((int)floor(points[i][0] * (resolution - 3)) + 1);
		points_processed[i].push_back((int)floor(points[i][1] * (resolution - 3)) + 1);
	}

	//  Loop through the rows of the image.
	for (pixelY = 0; pixelY < resolution; pixelY++) {

		//  Build a list of nodes.
		nodes = 0; 
		j = polyCorners - 1;
		for (i = 0; i < polyCorners; i++) {
            if (points_processed[i][1] < (double)pixelY && points_processed[j][1] >= (double)pixelY
                || points_processed[j][1] < (double)pixelY && points_processed[i][1] >= (double)pixelY) {
				nodeX[nodes++] = (int)(points_processed[i][0] + (pixelY - points_processed[i][1]) / (points_processed[j][1] - points_processed[i][1])
					* (points_processed[j][0] - points_processed[i][0]));
			}
			j = i;
		}

		//  Sort the nodes, via a simple “Bubble” sort.
		i = 0;
		while (i < nodes - 1) {
			if (nodeX[i] > nodeX[i + 1]) {
				swap = nodeX[i]; nodeX[i] = nodeX[i + 1]; nodeX[i + 1] = swap; if (i) i--;
			}
			else {
				i++;
			}
		}

		//  Fill the pixels between node pairs.
		for (i = 0; i < nodes; i += 2) {
			height_map[i].resize(resolution, water_height);
			if (nodeX[i] >= resolution) break;
			if (nodeX[i + 1] > 0) {
				if (nodeX[i] < 0) nodeX[i] = 0;
				if (nodeX[i + 1] > resolution) nodeX[i + 1] = resolution;
				for (pixelX = nodeX[i]; pixelX < nodeX[i + 1]; pixelX++) {
                    int splash = (int)abs(roughness * resolution * (pn.noise(roughness_frequency/20 * pixelX, roughness_frequency/20 * pixelY, scroll) - 0.5));
                    for (int h = std::max(pixelY-splash,0); h <= std::min(pixelY+splash,resolution-2); h++) {
                        height_map[pixelX][h] = float((land_noise * 2 * (perlinMatrix[pixelX][h] - 0.5) * range) + land_height);
                    }
                    for (int h = std::max(pixelX-splash,0); h <= std::min(pixelX+splash,resolution-2); h++) {
                        height_map[h][pixelY] = float((land_noise * 2 * (perlinMatrix[h][pixelY] - 0.5) * range) + land_height);
                    }
				}
			}
		}
	}
	return height_map;
}

void IslandGenerator::loadPoints() {
	std::vector<std::vector<float>> new_points;
	float point_x, point_y;
	size_t pos = 0;
	points_string.erase(std::remove(points_string.begin(), points_string.end(), '['), points_string.end());
	points_string.erase(std::remove(points_string.begin(), points_string.end(), ']'), points_string.end());
	std::string temp_string = points_string;
	std::string token;
	int i = 0;
	while ((pos = temp_string.find(',')) != std::string::npos) {
		token = temp_string.substr(0, pos);
		if (i == 0) {
			point_x = std::stof(token);
		}
		else {
			point_y = std::stof(token);
		}
		temp_string.erase(0, pos + 1);
		i++;
		if (i == 2) {
			new_points.push_back(std::vector<float>({ point_x, point_y }));
			i = 0;
		}
	}

	if (i == 0) {
		point_x = std::stof(temp_string);
	}
	else {
		point_y = std::stof(temp_string);
	}
	i++;
	if (i == 2) {
		new_points.push_back(std::vector<float>({ point_x, point_y }));
	}

	points = new_points;
}

void IslandGenerator::generateIsland() {
	loadPoints();
	perlinMatrix = generatePerlinMatrix();
	height_map = plotPolygon();
}
