//
// Created by Tomev on 29.05.2017.
//

#include "textDataParser.h"

#include <sstream>

void textDataParser::parseData(void *source, void *target)
{

  std::string *line = static_cast<std::string*>(source);
  sample *sampleHolder = static_cast<sample*>(target);

  std::istringstream ss(*line);
  std::string value;

  sampleHolder->values.clear();

  while(getline(ss, value, ',')) sampleHolder->values.push_back(value);

}
