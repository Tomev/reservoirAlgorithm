//
// Created by Tomev on 29.05.2017.
//

#ifndef RESERVOIRALGORITHM_DATAREADER_H
#define RESERVOIRALGORITHM_DATAREADER_H


class dataReader
{
  public:

    virtual void getNextRawDatum(void *target) = 0;
    virtual void gatherAttributesData(void *attributes) = 0;
    virtual bool hasMoreData() = 0;
};


#endif //RESERVOIRALGORITHM_DATAREADER_H
