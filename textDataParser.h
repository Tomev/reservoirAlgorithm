//
// Created by Tomev on 29.05.2017.
//

#ifndef RESERVOIRALGORITHM_TEXTDATAPARSER_H
#define RESERVOIRALGORITHM_TEXTDATAPARSER_H

#include "dataParser.h"

class textDataParser : public dataParser
{

  public:
    void parseData(void* source, void *target);

};


#endif //RESERVOIRALGORITHM_TEXTDATAPARSER_H
