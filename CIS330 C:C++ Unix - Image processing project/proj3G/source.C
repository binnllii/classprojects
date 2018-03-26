
#include "source.h"
#include "image.h"
#include "logging.h"

Image * source::GetOutput()
{
    return &image;
    
    
}

source::source(){
    image.setSource(this);
};
