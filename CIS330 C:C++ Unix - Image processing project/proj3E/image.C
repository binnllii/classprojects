#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include "source.h"

Image::Image(void)
{
    unsigned char * buffer = NULL;
    height = 0;
    width = 0;
    maxval = 0;
}

void Image::setWidth(int w)
{
    width = w;
    
}
void Image::setHeight(int h)
{
    height = h;
    
}

void Image::setValues(int w, int h)
{
    width = w;
    height = h;
}


int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

int Image::getMaxVal() const
{
    return maxval;
}

unsigned char * Image::getData() const
{
    return buffer;
}

void Image::setData()
{
    buffer = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
}





void Image::Update() const
{
    if(sour != NULL){
        sour->Update();
        
    }
}

void Image::setSource(source * s){
    sour = s;
}

void Image::setData2(int width, int height)
{
    buffer = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
}
