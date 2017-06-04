//
// Created by Tomev on 29.05.2017.
//

#ifndef RESERVOIRALGORITHM_TEXTDATAPARSER_H
#define RESERVOIRALGORITHM_TEXTDATAPARSER_H

#include <string>
#include <vector>
#include <c++/iostream>

#include "dataParser.h"

struct sample
{
  long dataId;
  std::vector<std::string> values;

  void print()
  {
    std::cout << "Step: " << dataId << ". Data: ";

    for(int i = 0; i < values.size(); ++i)
    {
      std::cout << values.at(i) << ", ";
    }

    std::cout << std::endl;
  }
};

class textDataParser : public dataParser
{

  public:
    void parseData(void* source, void *target);

};


#endif //RESERVOIRALGORITHM_TEXTDATAPARSER_H
