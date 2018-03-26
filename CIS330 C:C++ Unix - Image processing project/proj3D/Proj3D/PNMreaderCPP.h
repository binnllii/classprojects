#include "source.h"

#ifndef PNMREADER
#define PNMREADER

class PNMreaderCPP : public source
{
private:
    char *file;
public:
    PNMreaderCPP(char* file);
    virtual void Execute();
};
#endif
