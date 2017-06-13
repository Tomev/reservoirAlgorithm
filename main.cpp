#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <c++/random>
#include <c++/chrono>

#include "textDataReader.h"
#include "textDataParser.h"

#include "reservoirSamplingAlgorithm.h"
#include "biasedReservoirSamplingAlgorithm.h"

std::vector<attributeData> attributes;

void gatherAttributesData(textDataReader* tdr);

int main()
{
  // Initialize time-dependent random seed
  srand (time(NULL));

  std::ifstream sourceFile("D:\\Dysk Google\\Data Streams\\powersupply.arff");

  std::string line;

  textDataReader tdr(&sourceFile);
  textDataParser tdp;

  tdr.gatherAttributesData(&attributes);

  while(line.find("@data")) tdr.getNextRawDatum(&line);
  tdr.getNextRawDatum(&line);

  biasedReservoirSamplingAlgorithm a(&tdp, &tdr);
  //reservoirSamplingAlgorithm a(&tdr, &tdp);

  std::vector<sample> reservoir;

  a.fillReservoir(&reservoir);

  for(int i = 0; i < reservoir.size(); ++i)
  {
    std::cout << "Sample number " << i+1 << ": ";
    reservoir.at(i).print();
  }


  return 0;
}