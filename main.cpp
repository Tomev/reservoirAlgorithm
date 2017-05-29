#include <iostream>
#include <fstream>
#include <vector>

#include "textDataReader.h"

struct attributeData
{
  std::string attributeName;
  std::string attributeType;
};

int main()
{
  std::ifstream sourceFile("D:\\Dysk Google\\Data Streams\\powersupply.arff");

  std::string line;

  textDataReader tdr(&sourceFile);

  tdr.getNextRawDatum(&line);
  tdr.getNextRawDatum(&line);


  std::cout << line;

  return 0;
}