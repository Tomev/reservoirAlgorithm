//
// Created by Tomev on 05.06.2017.
//

#ifndef RESERVOIRALGORITHM_RESERVOIRSAMPLINGALGORITHM_H
#define RESERVOIRALGORITHM_RESERVOIRSAMPLINGALGORITHM_H

#include "dataParser.h"
#include "dataReader.h"

class reservoirSamplingAlgorithm
{
  public:
    virtual void fillReservoir(void *reservoir) = 0;

  protected:
    dataParser *parser;
    dataReader *reader;

    int stepsNumber = 10000;
};

#endif //RESERVOIRALGORITHM_RESERVOIRSAMPLINGALGORITHM_H
