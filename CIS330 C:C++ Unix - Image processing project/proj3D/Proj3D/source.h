#include "image.h"
#ifndef SOURCE
#define SOURCE

class source
{
    
public:
    virtual void Execute() = 0;
    
    Image * GetOutput();
    source();
    
private:
    unsigned char * img;
protected:
    Image image;
};





#endif
