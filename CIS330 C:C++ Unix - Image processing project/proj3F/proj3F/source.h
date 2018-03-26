#include "image.h"
#ifndef SOURCE_H
#define SOURCE_H

class source
{
    
public:
    
    virtual const char *SourceName() = 0;
    Image * GetOutput();
    source();
    virtual void Update() = 0;
private:
    unsigned char * img;
    
protected:
    Image image;
    virtual void Execute() = 0;
};





#endif
