#include "sink.h"
#include <stdio.h>

#ifndef PNMWRITER
#define PNMWRITER

class PNMwriterCPP: public Sink
{
public:
    void Write(char* filename);

};

#endif
