#ifndef SINK
#define SINK
#include "image.h"

class Sink
{
protected:
    Image * input1;
    Image * input2;
public:
    void SetInput(Image * input1);
    void SetInput2(Image * input2);
    Sink();

    
};




#endif
