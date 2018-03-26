#include "image.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Image::Image(void)
{
    width = 0;
	height = 0;
	
	buffer = NULL;
}

Image::Image(int h, int w, unsigned char *b)
{
	height = h;
	width = w;
	buffer = (unsigned char *) malloc(3 * height * width);
	memcpy(buffer, b, 3 * height * width);;
}

Image::Image(const Image &img)
{
	buffer = (unsigned char *) malloc(3 * height*width);
    width = img.width;
    height = img.height;
	memcpy(buffer, img.buffer, 3 * height * width);
}

void Image::ResetSize(int w, int h)
{
	width = w;
	height = h;
}

void Image::setData(unsigned char *b)
{
    
	if (buffer == NULL) {
		buffer = (unsigned char *) malloc(3 * width * height);
	}
	memcpy(buffer, b, 3 * height * width);
}

int Image::getWidth()
{
	return width;
}

int Image::getHeight()
{
	return height;
}

unsigned char* Image::getData()
{
	return buffer;
}
