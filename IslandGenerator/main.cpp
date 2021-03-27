// main.cpp
#include <iostream>
#include <string.h>
#include "./islandgenerator.h"

int main(int argc, char *argv[])
{
    IslandGenerator islandGenerator;
    std::string arguments[16];
    arguments[0] = "[0,0],[1,0],[1,1],[0,1]";
    arguments[1] = "0.0";
    arguments[2] = "0.01";
    arguments[3] = "0.0";
    arguments[4] = "0.01";
    arguments[5] = "0.0";
    arguments[6] = "8.0";
    arguments[7] = "40";
    arguments[8] = "0.00";
    arguments[9] = "0.00";
    arguments[10] = "0.00";
    arguments[11] = "1.0";
    arguments[12] = "0";
    arguments[13] = "0";
    arguments[14] = "0";
    arguments[15] = "8";

    for (int i = 1; i < argc; ++i)
        arguments[i - 1] = argv[i];

    islandGenerator.setPointsString(arguments[0]);
    islandGenerator.setLandNoise(std::stof(arguments[1]));
    islandGenerator.setLand(std::stof(arguments[2]));
    islandGenerator.setSeabedNoise(std::stof(arguments[3]));
    islandGenerator.setSeabed(std::stof(arguments[4]));
    islandGenerator.setWaterHeight(std::stof(arguments[5]));
    islandGenerator.setFrequency(std::stof(arguments[6]));
    islandGenerator.setResolution(std::stof(arguments[7]));
    islandGenerator.setOctaves(std::stof(arguments[8]));
    islandGenerator.setScroll(std::stof(arguments[9]));
    islandGenerator.setRoughness(std::stof(arguments[10]));
    islandGenerator.setRoughnessFrequency(std::stof(arguments[11]));
    islandGenerator.setFlatnessStrength(std::stof(arguments[12]));
    islandGenerator.setFlatnessSize(std::stof(arguments[13]));
    islandGenerator.setFlatnessFreq(std::stof(arguments[14]));
    islandGenerator.setSeed(std::stoi(arguments[15]));

    islandGenerator.generateIsland();

    islandGenerator.saveToFile();
}
