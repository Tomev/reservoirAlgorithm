//
// Created by Tomev on 29.05.2017.
//

#ifndef RESERVOIRALGORITHM_RESERVOIRSAMPLINGALGORITHM_H
#define RESERVOIRALGORITHM_RESERVOIRSAMPLINGALGORITHM_H

#include "textDataReader.h"
#include "textDataParser.h"

class reservoirSamplingAlgorithm
{

  public:

    reservoirSamplingAlgorithm(textDataReader *reader, textDataParser* parser);
    void fillReservoir(std::vector<sample> *reservoir);

  private:
    const int RESERVOIR_SIZE = 1000;
    const int STEPS_NUMBER = 20000;

    textDataReader *reader;
    textDataParser *parser;

    void initializeReservoir(std::vector<sample> *reservoir);

};


#endif //RESERVOIRALGORITHM_RESERVOIRSAMPLINGALGORITHM_H
