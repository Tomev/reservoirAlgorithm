#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "textDataReader.h"

struct attributeData
{
  std::string attributeName;
  std::string attributeType;
};

std::vector<attributeData> attributes;

void gatherAttributesData(textDataReader* tdr);

int main()
{
  std::ifstream sourceFile("D:\\Dysk Google\\Data Streams\\powersupply.arff");

  std::string line;

  textDataReader tdr(&sourceFile);

  gatherAttributesData(&tdr);

  for(int i = 0; i < attributes.size(); ++i)
  {
    std::cout << attributes.at(i).attributeName << " ";
    std::cout << attributes.at(i).attributeType << std::endl;
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