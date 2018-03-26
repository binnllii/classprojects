#include <stdio.h>
#ifndef IMAGE_H
#define IMAGE_H


class Image
{
    private:
        unsigned char *buffer;
    
        int height, width, maxval;

    public:
        Image(void);
        void setValues(int, int);
        int getHeight();
        int getWidth();
        int getMaxVal();
        void setBuffer();
        void setBuffer2(int,int);
        unsigned char* getBuffer();
};


#endif
