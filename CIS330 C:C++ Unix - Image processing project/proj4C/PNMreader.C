
#include "PNMreader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "logging.h"
#include "filters.h"

using namespace std;

PNMreader::PNMreader(char *file)
{
    this->file = file;


}
void PNMreader::Update()
{
    char msg[128];
    sprintf(msg, "%s: about Execute\n", SourceName());
    Logger::LogEvent(msg);
    Execute();
    sprintf(msg, "%s: Done executing\n", SourceName());
    Logger::LogEvent(msg);
 
    
}

void PNMreader::Execute()
{

    ifstream file(this->file);
    char magicNum[128];
    int  width, height, maxval;
    char p6[3];
    
    
    
    file >> p6 >> width >> height >> maxval;
    file.ignore(1024, '\n');
    image.setValues(width,height);
    image.setData2(width, height);
    file.read((char*)image.getData(), 3*width*height);
}

const char *PNMreader::SourceName(){
    return "PNMreader";
}



