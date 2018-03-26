#include "PNMwriter.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>




using namespace std;

void PNMwriter::Write(char* filename)
{

    ofstream file(filename);
    char P6[3] = "P6";
    int width = input1->getWidth();
    int height = input1->getHeight();
    file << P6 << width << " " << height << endl;
    file << 255 << endl;
    file.write((char*)input1->getData(), 3*width*height);
    file.close();
}

const char *PNMwriter::SinkName(){
    return "PNMwriter";
}
