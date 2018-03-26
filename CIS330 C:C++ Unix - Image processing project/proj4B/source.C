#include "source.h"
#include "image.h"


Image * source::GetOutput()
{
    return &image;
}

source::source(){
    image.setSource(this);
};
