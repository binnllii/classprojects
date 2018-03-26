
#include "PNMreaderCPP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>


using namespace std;

PNMreaderCPP::PNMreaderCPP(char *file)
{
    this->file = file;
    char * f = (char *) malloc(strlen(file+1));
    strcpy(f,file);

};

void PNMreaderCPP::Execute()
{

    ifstream file;
    char magicNum[128];
    int  width, height, maxval;
    file.open(this->file);
    char p6[3];
    if(!file){
        std::cerr << "unable to open file " << endl;
    }
    file >> p6 >> width >> height >> maxval;
    file.ignore(1024, '\n');
    image.setValues(width,height);
    image.setBuffer2(width, height);
    file.read((char*)image.getBuffer(), 3*width*height);
};





