#include "image.h"
#ifndef SINK_H
#define SINK_H

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
