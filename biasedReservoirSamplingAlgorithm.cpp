//
// Created by Tomev on 03.06.2017.
//

#include "biasedReservoirSamplingAlgorithm.h"

biasedReservoirSamplingAlgorithm::biasedReservoirSamplingAlgorithm(textDataParser *parser, textDataReader *reader):
reader(reader), parser(parser){}

void biasedReservoirSamplingAlgorithm::fillReservoir(std::vector<sample> *reservoir)
{
    std::string rawData;
    int indexOfSampleToWriteOn;

    // For each incoming data sample
    for(int step = 0; step < STEPS_NUMBER; ++step)
    {
      updateFractionOfReservoirFilled(reservoir);

      // Check if a sample should be removed
      if(fractionOfReservoirFilled >= ((double) rand() / (RAND_MAX)))
      {
          // If so randomly choose a sample
          indexOfSampleToWriteOn = (((double) rand() / (RAND_MAX)) * (reservoir->size()-1));
      }
      else
      {
          // If not add new sample to reservoir
          indexOfSampleToWriteOn = reservoir->size();
          reservoir->push_back(sample());
      }

      // Add new data to the reservoir
      reader->getNextRawDatum(&rawData);
      parser->parseData(&rawData, &(reservoir->at(indexOfSampleToWriteOn)));
      reservoir->at(indexOfSampleToWriteOn).dataId = step;
    }
}

void biasedReservoirSamplingAlgorithm::updateFractionOfReservoirFilled(std::vector<sample> * reservoir)
{
    // Bias rate is equal to 1 over reservoir capacity, thus:
    this->fractionOfReservoirFilled = reservoir->size() * biasRate;
}


