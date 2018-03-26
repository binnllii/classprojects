#include "image.h"
#include <stdio.h>
#include <stdlib.h>

Image::Image(void)
{
    unsigned char * buffer = NULL;
    height = 0;
    width = 0;
    maxval = 0;
}

void Image::setValues(int w, int h)
{
    width = w;
    height = h;
}


int Image::getWidth()
{
    return width;
}

int Image::getHeight()
{
    return height;
}

int Image::getMaxVal()
{
    return maxval;
}

unsigned char * Image::getData()
{
    return buffer;
}

void Image::setData()
{
    buffer = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
}
