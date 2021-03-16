#include <iostream>
#include <string.h>
#include "./islandgenerator.h"

int main(int argc, char *argv[])
{
   IslandGenerator islandGenerator;
   std::string points;

   points = std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
            std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   srand(time(NULL));

   islandGenerator.setPointsString(points);
   islandGenerator.setLandNoise(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setLand(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setSeabedNoise(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setSeabed(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setWaterHeight(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setFrequency(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setResolution(rand() % 100);
   islandGenerator.setOctaves(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setScroll(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setRoughness(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setRoughnessFrequency(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
   islandGenerator.setSeed(rand());

   islandGenerator.generateIsland();

   islandGenerator.saveToFile();
}
