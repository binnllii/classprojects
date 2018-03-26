#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include "source.h"

Image::Image(void)
{
    buffer = NULL;
    height = 0;
    width = 0;
    maxval = 0;
}

//Image::~Image()
//{
//    free(buffer);
//}

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
    if(buffer == NULL){
        buffer = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
    }
}

void Image::freeData(){
    free(buffer);
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

//void Image::setData2(int width, int height)
//{
//    if(buffer == NULL && width > 0 && height > ){    
//        buffer = (unsigned char*) malloc(sizeof(unsigned char) * 3 * height * width);
//    }       
//}

Image::~Image()
{
    free(buffer);
}
