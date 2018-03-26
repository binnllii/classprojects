#include "PNMreader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



PNMreader::PNMreader(char *file)
{
    this->file = file;
}




void PNMreader::Execute()
{
    FILE *file = fopen(this->file, "rb");
    char magicNum[128];
    int  width, height, maxval;
    fscanf(file, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
    image.setValues(width, height);
    image.setData();
    fread(image.getData(), sizeof(unsigned char), 3 * image.getWidth()*image.getHeight(), file);
    fclose(file);
}


