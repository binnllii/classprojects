#include <PNMreader.h>
#include <image.h>

#include <stdlib.h>
#include <stdio.h>

void PNMreader::read(const char *filename, Image &output){
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        fprintf(stderr, "ubable to open file \n");
        exit(EXIT_FAILURE);
    }
    int w,h;
    fscanf(f, "P6\n%d %d\n255\n", &w, &h);
    fprintf(stderr, "W = %d, h = %d\n, w, h);
}
