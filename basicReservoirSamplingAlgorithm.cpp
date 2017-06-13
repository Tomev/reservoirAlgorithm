//
// Created by Tomev on 29.05.2017.
//

#include "basicReservoirSamplingAlgorithm.h"

basicReservoirSamplingAlgorithm::basicReservoirSamplingAlgorithm(
        dataReader *reader, dataParser *parser, int reservoirMaxSize, int stepsNumber) :
        reservoirMaxSize(reservoirMaxSize)
{
  this->reader = reader;
  this->parser = parser;
  this->stepsNumber = stepsNumber;
}

void basicReservoirSamplingAlgorithm::fillReservoir(std::vector<sample*> *reservoir)
{
  initializeReservoir(reservoir);

  double addChance;

  for(int step = reservoirMaxSize+1; step < reservoirMaxSize; ++step)
  {
    addChance = (double) reservoirMaxSize/step;

    if(addChance > ((double) rand() / (RAND_MAX)))
    {
      // Adding to reservoir
      int idxToDelete = (((double) rand() / (RAND_MAX)) * reservoirMaxSize);

      reader->getNextRawDatum(parser->buffor);
      parser->writeDatumOnPosition(reservoir, idxToDelete);
    }
  }
}

void basicReservoirSamplingAlgorithm::initializeReservoir(std::vector<sample*> *reservoir)
{
  while(reservoir->size() < reservoirMaxSize) addDatumToReservoir(reservoir);
}

void basicReservoirSamplingAlgorithm::performSingleStep(std::vector<sample*> *reservoir)
{
  if(reservoir->size() < reservoirMaxSize) addDatumToReservoir(reservoir);

}

void basicReservoirSamplingAlgorithm::addDatumToReservoir(std::vector<sample *> *reservoir)
{
  reader->getNextRawDatum(parser->buffor);

  parser->addDatumToContainer(reservoir);

  parser->writeDatumOnPosition(reservoir, reservoir->size()-1);
}
