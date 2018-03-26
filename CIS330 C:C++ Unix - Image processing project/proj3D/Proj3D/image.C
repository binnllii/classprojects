#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

unsigned char * Image::getBuffer()
{
    return buffer;
}

void Image::setBuffer()
{
    buffer = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
}

void Image::setBuffer2(int width, int height)
{
    buffer = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
}

