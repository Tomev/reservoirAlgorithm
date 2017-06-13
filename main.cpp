#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <c++/random>
#include <c++/chrono>

#include "textDataReader.h"
#include "textDataParser.h"

#include "basicReservoirSamplingAlgorithm.h"
#include "biasedReservoirSamplingAlgorithm.h"

int main()
{
  // Initialize time-dependent random seed
  srand (time(NULL));

  std::ifstream sourceFile("D:\\Dysk Google\\Data Streams\\powersupply.arff");

  std::string line;

  textDataReader tdr(&sourceFile);
  textDataParser tdp;

  tdr.gatherAttributesData(NULL);

  biasedReservoirSamplingAlgorithm a(&tdr, &tdp, 1000, 20000);
  //basicReservoirSamplingAlgorithm a(&tdr, &tdp, 1000, 10000);

  std::vector<sample*> reservoir;

  a.fillReservoir(&reservoir);

  for(int i = 0; i < reservoir.size(); ++i)
  {
    std::cout << "Sample number " << i+1 << ": ";
    reservoir.at(i)->print();
  }

  return 0;
}