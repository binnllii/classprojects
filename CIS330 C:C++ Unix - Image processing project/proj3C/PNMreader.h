#include "source.h"

#ifndef PNMREADER
#define PNMREADER

class PNMreader : public source
{
private:
    char *file;
public:
    PNMreader(char* file);

    virtual void Execute();
    

    
};
#endif
