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

struct attributeData
{
  std::string attributeName;
  std::string attributeType;
};

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

  gatherAttributesData(&tdr);

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

void gatherAttributesData(textDataReader* tdr)
{
  // This only works for .arff files. Not tested for others.

  std::string line;

  // While line doesn't start with @attribute
  while(line.find("@attribute")) tdr->getNextRawDatum(&line);

  // While line starts with @attribute
  while(!line.find("@attribute"))
  {
    std::istringstream ss(line);
    std::string substring;

    getline(ss, substring, ' ');

    attributes.push_back(attributeData());

    getline(ss, substring, ' ');

    attributes.at(attributes.size()-1).attributeName = substring;

    getline(ss, substring, ' ');

    if(substring.find("Numeric")==0) attributes.at(attributes.size()-1).attributeType = substring;
    else attributes.at(attributes.size()-1).attributeType = "Symbolic";

    tdr->getNextRawDatum(&line);
  }

}