//
// Created by Tomev on 29.05.2017.
//

#ifndef RESERVOIRALGORITHM_DATAPARSER_H
#define RESERVOIRALGORITHM_DATAPARSER_H

#include <string>
#include <vector>
#include <c++/iostream>

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

class dataParser
{
  public:

    virtual void parseData(void* source, void *target) = 0;
};


#endif //RESERVOIRALGORITHM_DATAPARSER_H
