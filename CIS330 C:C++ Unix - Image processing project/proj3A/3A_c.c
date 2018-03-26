#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct
{
    /* data members go here */
    int width;
    int height;
    Pixel *pixel;

} Image;

Image *
ReadImage(char *filename)
{
// These lines are useful:
    char magicNum[128];
    int width, height, maxval;
    FILE *f_in;
    Image *img = NULL;
    f_in = fopen(filename, "rb");
    img = malloc(sizeof(Image));
    fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval); 
    img->width = width;
    img->height = height;
    img->pixel = malloc(sizeof(Pixel)*img->width*img->height);
    fread(img->pixel, sizeof(Pixel),img->width * img->height, f_in); 
    fclose(f_in);
    return img;
//  where f_in is the name of the input FILE.
 
    
}


void WriteImage(Image *img, char *filename)
{ 
    FILE *f_out;
    f_out = fopen(filename, "wb");

    fprintf(f_out, "P6\n");
    fprintf(f_out, "%d %d\n", img->width, img->height);
    
    fprintf(f_out, "255\n");
    fwrite(img->pixel, 3*img->width, img->height, f_out);
    fclose(f_out);
}

Image *
YellowDiagonal(Image *input)
{
    Image *output;
    output = malloc(sizeof(Image));
    output->height = input->height;
    output->width = input->width;
    output->pixel = malloc(output->height * output->width * sizeof(Pixel));
    memcpy(output->pixel, input->pixel, output->height * output->width * sizeof(Pixel));
    int i,temp;
    for(i = 0; i < output->width; i++){
        if(i < output->height)
        {
            temp = ((output->width*i)+i);
            output->pixel[temp].r = 255;
            output->pixel[temp].b = 0;
            output->pixel[temp].g = 255;
        } 
    }
    return output;   
}

int main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write */
    Image *image;
    image = ReadImage(argv[1]);
    image = YellowDiagonal(image);
    WriteImage(image, argv[2]);
    free(image);
}
