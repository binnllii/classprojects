#include <image.h>
#include <stdlib.h>

Image::Image(){
    width = 0;
    height = 0;
    buffer = NULL;

}

Image::~Image(){
    if(buffer != NULL){
        delete buffer;
    }
}


void Image::ResetSize(int w, int h){
    if (buffer != NULL){
        delete [] buffer;

    }
    width = w;
    height = h;
    buffer = new Pixel[w*h];
}
