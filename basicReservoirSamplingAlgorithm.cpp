//
// Created by Tomev on 29.05.2017.
//

#include "basicReservoirSamplingAlgorithm.h"

basicReservoirSamplingAlgorithm::basicReservoirSamplingAlgorithm(dataReader *reader, dataParser *parser) :
reader(reader), parser(parser) {}

void basicReservoirSamplingAlgorithm::fillReservoir(void *reservoir)
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

      parser->writeDatumOnPosition(&rawData, reservoir, idxToDelete);
    }
  }
}

void basicReservoirSamplingAlgorithm::initializeReservoir(void *reservoir)
{
    std::string rawData;

    for(int step = 0; step < RESERVOIR_SIZE; ++step)
    {
        reader->getNextRawDatum(&rawData);

        parser->addDatumToContainer(reservoir);

        parser->writeDatumOnPosition(&rawData, reservoir, step);
    }
}
