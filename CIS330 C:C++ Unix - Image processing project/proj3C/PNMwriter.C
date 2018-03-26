#include "PNMwriter.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>




void PNMwriter::Write(char* filename)
{
    
    FILE *file = fopen(filename, "wb");
    fprintf(file, "%s\n %d %d\n %d\n", "P6", input1->getWidth(), input1->getHeight(), 255);
    fwrite(input1->getData(), sizeof(unsigned char), 3 * input1->getHeight()*input1->getWidth(), file);
    fclose(file);
}


