#include "sink.h"
#include <stdio.h>

#ifndef PNMWRITER_H
#define PNMWRITER_H

class PNMwriter: public Sink
{
public:
    void Write(char* filename);

};

#endif
