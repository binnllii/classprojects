#include "PNMreader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>


using namespace std;

PNMreader::PNMreader(char *file)
{
    this->file = file;
    
    
}

PNMreader::~PNMreader(){
    free(image.getData());
    
}


void PNMreader::Update()
{
    Execute();
}


void PNMreader::Execute()
{
    
    ifstream file(this->file);
    char magicNum[128];
    int  width, height, maxval;
    //    file.open(this->file);
    char p6[3];
    if(!file.is_open()){
        std::cerr << "unable to open file " << endl;
    }
    file >> p6 >> width >> height >> maxval;
    file.ignore(1024, '\n');
    image.setValues(width,height);
    image.setData2(width, height);
    file.read((char*)image.getData(), 3*width*height);
}




