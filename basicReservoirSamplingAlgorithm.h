//
// Created by Tomev on 29.05.2017.
//

#ifndef RESERVOIRALGORITHM_BASICRESERVOIRSAMPLINGALGORITHM_H
#define RESERVOIRALGORITHM_BASICRESERVOIRSAMPLINGALGORITHM_H

#include <random>

#include "reservoirSamplingAlgorithm.h"

class basicReservoirSamplingAlgorithm : public reservoirSamplingAlgorithm
{

  public:

  basicReservoirSamplingAlgorithm(dataReader *reader, dataParser* parser);
    void fillReservoir(void *reservoir);

  private:
    const int RESERVOIR_SIZE = 1000;
    const int STEPS_NUMBER = 20000;

    dataReader *reader;
    dataParser *parser;


    void initializeReservoir(void *reservoir);

};


#endif //RESERVOIRALGORITHM_BASICRESERVOIRSAMPLINGALGORITHM_H
