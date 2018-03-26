#include "image.h"
#ifndef SOURCE
#define SOURCE

class source
{
    
public:
    
    Image * GetOutput();
    source();
    
private:
    unsigned char * img;
   virtual void Update() = 0;
protected:
    Image image;
    virtual void Execute() = 0;
    
};





#endif
