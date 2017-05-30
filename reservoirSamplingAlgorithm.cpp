//
// Created by Tomev on 29.05.2017.
//

#include "reservoirSamplingAlgorithm.h"

reservoirSamplingAlgorithm::reservoirSamplingAlgorithm(textDataReader *reader, textDataParser *parser) :
reader(reader), parser(parser) {}

void reservoirSamplingAlgorithm::fillReservoir(std::vector<sample> *reservoir)
{
  initializeReservoir(reservoir);

  std::string rawData;

  double addChance;

  for(int step = RESERVOIR_SIZE+1; step < STEPS_NUMBER; ++step)
  {
    addChance = (double) RESERVOIR_SIZE/step;
    reader->getNextRawDatum(&rawData);

    if(addChance > ((double) rand() / (RAND_MAX)))
    {
      // Adding to reservoir
      int idxToDelete = (((double) rand() / (RAND_MAX)) * RESERVOIR_SIZE);

      parser->parseData(&rawData, &(reservoir->at(idxToDelete)));

      reservoir->at(idxToDelete).dataId = step;
    }
  }
}

void reservoirSamplingAlgorithm::initializeReservoir(std::vector<sample> *reservoir)
{
    std::string rawData;

    for(int step = 0; step < RESERVOIR_SIZE; ++step)
    {
        reader->getNextRawDatum(&rawData);

        reservoir->push_back(sample());

        parser->parseData(&rawData, &(reservoir->at(reservoir->size()-1)));
        reservoir->at(reservoir->size()-1).dataId = step;
    }
}
