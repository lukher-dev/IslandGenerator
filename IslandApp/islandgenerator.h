#ifndef ISLANDGENERATOR_H
#define ISLANDGENERATOR_H

#include <vector>
#include <string>

class IslandGenerator
{
protected:
    std::vector<std::vector<float>> generateHeightMap();
    std::vector<std::vector<float>> generatePerlinMatrix();
    std::vector<std::vector<float>> plotLine(std::vector<std::vector<float>> heightMap,std::vector<std::vector<float>> perlinMatrix, float fixed_x0, float fixed_y0, float fixed_x1, float fixed_y1);
    std::vector<std::vector<float>> plotPolygon(std::vector<std::vector<float>> heightMap,std::vector<std::vector<float>> perlinMatrix, std::vector<std::vector<float>> points);
    void spawnWater(std::vector<std::vector<float>>& heightMap, std::vector<std::vector<float>>& perlinMatrix, int i, int j);
    void raiseLand(std::vector<std::vector<float>>& heightMap, std::vector<std::vector<float>>& perlinMatrix);
public:
    IslandGenerator();
    void setLandNoise(float amount){land_noise = amount;};
    void setLand(float amount){land_height = amount;};
    void setFrequency(float amount){frequency = amount;};
    void setResolution(int number){resolution = number;};
    void setSeabedNoise(float amount){seabed_noise = amount;};
    void setSeabed(float amount){seabed_height = amount;};
    void setOctaves(float amount){octaves = amount;};
    void setScroll(float amount){scroll = amount;};
    void setRoughness(float amount){roughness = amount;};
    void setRoughnessFrequency(float amount){roughness_frequency = amount;};
    void setWaterHeight(float amount){water_height = amount;};
    void setName(std::string in_name){name = in_name;};
    void setPointsString(std::string in_string){points_string = in_string;};
    void setSeed(int in_seed){seed = in_seed;};
    int getResolution() {return resolution;};
    std::vector<std::vector<float>>  getIsland(){return height_map;};
    void saveToFile();
    void loadPoints();
    void generateIsland();

private:
    float land_noise;
    float land_height;
    float frequency;
    int resolution;
    float seabed_noise;
    float seabed_height;
    float octaves;
    float scroll;
    float roughness;
    float roughness_frequency;
    float water_height;
    int seed;
    std::string name;
    std::string points_string;
    std::vector<std::vector<float>> height_map;
    std::vector<std::vector<float>> perlinMatrix;
    std::vector<std::vector<float>> points;
};

#endif // ISLANDGENERATOR_H
