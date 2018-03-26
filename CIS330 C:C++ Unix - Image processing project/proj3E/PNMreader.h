#include "source.h"
#include <stdio.h>

#ifndef PNMREADER_H
#define PNMREADER_H

class PNMreader : public source
{
private:
    char *file;
public:
    PNMreader(char* file);
    virtual void Execute();
    virtual void Update();
    ~PNMreader();
};
#endif
