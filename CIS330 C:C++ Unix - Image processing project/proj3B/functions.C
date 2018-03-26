//#include <image.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void ReadImage(char *filename, Image &output)
{
    FILE *file = fopen(filename, "rb");
    char magicNum[128];
    int width, height, maxval;

    fscanf(file, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
    unsigned char *temp = (unsigned char *) malloc(sizeof(unsigned char) *3*width*height);
    fread(temp, sizeof(unsigned char)*3, height*width, file);
    output.ResetSize(width, height);
    output.setData(temp);
    fclose(file);
    free(temp);
}
void WriteImage(char *filename, Image &img)
{
    FILE *file = fopen(filename, "wb");
    fprintf(file, "%s\n%d %d\n%d\n", "P6", img.getWidth(), img.getHeight(), 255);
    fwrite(img.getData(), sizeof(unsigned char) *3, img.getWidth()*img.getHeight(),file);
    fclose(file);
}

void HalveInSize(Image &input, Image &output)
{
    int width = input.getWidth();
    int halfW = (input.getWidth())/2;
    int halfH = (input.getHeight())/2;
    output.ResetSize(halfW, halfH);
    
    unsigned char *temp = (unsigned char *) malloc(halfW*halfH*3);
    int i, j;
    for(i = 0; i < halfH; i++){
        for(j = 0; j < halfW; j++){
            int in = 3*(i*2*width+j*2);
            int out = 3*(i*halfW+j);

            temp[out] = input.getData()[in];
            temp[out+1] = input.getData()[in+1];
            temp[out+2] = input.getData()[in+2];
        }
    }
    output.setData(temp);
    free(temp);

}
void LeftRightConcatenate(Image &leftInput, Image &rightinput, Image &output)
{
    int width1 = leftInput.getWidth();
    int width2 = rightinput.getWidth();
    int height1 = leftInput.getHeight();
    int height2 = rightinput.getHeight();
    int outH = (height1+height2)/2;
    int outW = (width1+width2);

    output.ResetSize(outW, outH);

    unsigned char * temp = (unsigned char *) malloc(outH*outW*3);
    
    for(int i = 0; i < width1; i++){
        for(int j = 0; j < outH; j++){
            int out = (j * outW + i) * 3;
            int in = (j * width1 + i) * 3;

            temp[out] = leftInput.getData()[in];
            temp[out+1] = leftInput.getData()[in+1];
            temp[out+2] = leftInput.getData()[in+2];
        }
    }

    for(int i = 0; i < width2; i++){
        for(int j = 0; j < outH; j++){
            int out = (j*outW +width1+i) * 3;
            int in2 = (j * width2 + i) * 3;
            
            temp[out] = rightinput.getData()[in2];
            temp[out+1] = rightinput.getData()[in2+1];
            temp[out+2] = rightinput.getData()[in2+2];
        }
    }    
    output.setData(temp);
    free(temp);
}
void TopBottomConcatenate(Image &topInput, Image &bottomInput, Image &output)
{
    int width1 = topInput.getWidth();
    int width2 = bottomInput.getWidth();
    int height1 = topInput.getHeight();
    int height2 = bottomInput.getHeight();
    int outH = height1+height2;
    int outW = (width1+width2)/2;

    output.ResetSize(outW, outH);
    
    unsigned char * temp = (unsigned char *) malloc(outH*outW*3);
    
    for(int i = 0; i < outW; i++){
        for(int j = 0; j < height1; j++){
            int out = (j * outW + i) * 3;
            int in = (j * width1 + i) * 3;

            temp[out] = topInput.getData()[in];
            temp[out+1] = topInput.getData()[in+1];
            temp[out+2] = topInput.getData()[in+2];
        }
    }

    for(int i = 0; i < outW; i++){
        for(int j = 0; j < height2; j++){
            int out = ((j + height1)*outW +i) * 3;
            int in2 = (j * width2 + i) * 3;

            temp[out] = bottomInput.getData()[in2];
            temp[out+1] = bottomInput.getData()[in2+1];
            temp[out+2] = bottomInput.getData()[in2+2];
        }
    }
    output.setData(temp);
    free(temp);

}
void Blend(Image &input1, Image &input2, float factor, Image &output)
{
    int width1 = input1.getWidth();
    int width2 = input2.getWidth();
    int height1 = input1.getHeight();
    int height2 = input2.getHeight();
    int outH = (height1+height2)/2;
    int outW = (width1+width2)/2;
    float fact = factor;

    output.ResetSize(outW,outH);

    unsigned char * temp = (unsigned char *) malloc(outH*outW*3);

    for(int i = 0; i < outW; i++){
        for(int j = 0; j < outH; j++){
            int count = (j*outW+i)*3;

            temp[count] = input1.getData()[count]*fact + input2.getData()[count]*(1-fact); 

            temp[count+1] = input1.getData()[count+1]*fact + input2.getData()[count]*(1-fact); 

            temp[count+2] = input1.getData()[count+2]*fact + input2.getData()[count]*(1-fact); 
            

        }
        
    }
    output.setData(temp);
    free(temp);
}
