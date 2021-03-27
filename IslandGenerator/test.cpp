#include <iostream>
#include <string.h>
#include "./islandgenerator.h"

int main(int argc, char *argv[])
{
   IslandGenerator islandGenerator;
   srand(time(NULL));

   for(int i = 0; i<RAND_MAX; i++){
      std::string points = "";
      std::cout<<i<<" of "<<RAND_MAX<<"\n";
      for(int j = 0; j< rand() % 16; j += 2){
      points += std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
               std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + ",";
      }
      points += std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) + "," +
         std::to_string(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));

      islandGenerator.setPointsString(points);
      islandGenerator.setLandNoise((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setLand((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setSeabedNoise((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setSeabed((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setWaterHeight((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setFrequency((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setResolution((rand() % 100) + 2);
      islandGenerator.setOctaves((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setScroll((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setFlatnessStrength((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setFlatnessFreq((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setFlatnessSize((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setRoughness((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setRoughnessFrequency((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))*1000);
      islandGenerator.setSeed(rand());

      islandGenerator.generateIsland();

      islandGenerator.saveToFile();
   }
}
