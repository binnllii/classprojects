#include "image.h"
#include "filters.h"
#include "sink.h"
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logging.h"
#include <exception>
#include <sys/time.h>

using namespace std;


const char *Color::FilterName() {
    return "Color";
};
const char * CheckSum::SinkName(){
    return "CheckSum";
};

const char * Blender::FilterName(){
    return "Blender";
};

const char * TBConcat::FilterName(){
    return "TBConcat";
};

const char * LRConcat::FilterName(){
    return "LRConcat";
};

const char * Shrinker::FilterName(){
    return "Shrinker";
};

const char * Rotate::FilterName(){
    return "Rotate";
};

const char * Subtract::FilterName(){
    return "Subtract";
};

const char * Blur::FilterName(){
    return "Blur";
};

const char * Grayscale::FilterName(){
    return "Grayscale";
};

const char * Mirror::FilterName(){
    return "Mirror";
};

Color::Color(int wid, int heig, unsigned char r, unsigned char g, unsigned char b){
    width = wid;
    height = heig;
    red = r;
    green = g;
    blue = b;
  
}

void Blender::SetFactor(float percent)
{
    this->percent = percent;
}

void Shrinker::Execute()
{
    //outputs half width half height
    int halfWid = input1->getWidth() / 2;
    int halfHeig = input1->getHeight() / 2;
    
    //image.setValues(halfWid, halfHeig);
    image.setWidth(halfWid);
    image.setHeight(halfHeig);
    image.setData();
    
    for(int i = 0; i < image.getHeight(); i++){
        for(int j = 0; j < image.getWidth(); j++){
            int index = 3 * (i*image.getWidth()+j);
            int oIndex = 3 * (2 * i * input1->getWidth() + j * 2);
            
            image.getData()[index] = input1->getData()[oIndex];
            image.getData()[index + 1] = input1->getData()[oIndex + 1];
            image.getData()[index + 2] = input1->getData()[oIndex + 2];
        }
    }
}


void LRConcat::Execute()
{
    
    if(input1 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input1\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input2 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input2\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input1->getHeight() != input2->getHeight()){
        char msg[1024];
        sprintf(msg, "%s: Height must match: %d, %d\n", SinkName(), input1->getHeight(), input2->getHeight());

        DataFlowException f(SinkName(), msg);
        throw f;
        
        
    }
    if(input1->getWidth() != input2->getWidth()){
        char msg[1024];
        sprintf(msg, "%s: Widths must match: %d, %d\n", SinkName(), input1->getWidth(), input2->getWidth());
        DataFlowException f(SinkName(), msg);
        throw f;
        
        
    }
    else{
        
        
        //2 input same height output single image combined left to right
        int wid = input1->getWidth() + input2->getWidth();
        int heig;
        
        if(input1->getHeight() > input2->getHeight()){
            heig = input1->getHeight();
        } else {
            heig = input2->getHeight();
        }
        
        image.setValues(wid, heig);
        image.setData();
        
        for(int i = 0; i < image.getHeight(); i++){
            for(int j = 0; j < image.getWidth(); j++){
                int index = 3 * (i * image.getWidth() + j);
                
                if(j < input1->getWidth()){
                    int oIndex = 3 *(i * input1->getWidth()+j);
                    image.getData()[index] = input1->getData()[oIndex];
                    image.getData()[index + 1] = input1->getData()[oIndex + 1];
                    image.getData()[index + 2] = input1->getData()[oIndex + 2];
                } else {
                    int oIndex = 3 * ((i * input2->getWidth() + j) - input1->getWidth());
                    image.getData()[index] = input2->getData()[oIndex];
                    image.getData()[index + 1] = input2->getData()[oIndex + 1];
                    image.getData()[index + 2] = input2->getData()[oIndex + 2];
                }
            }
        }
    }
}

void TBConcat::Execute()
{
    if(input1 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input1\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input2 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input2\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input1->getHeight() != input2->getHeight()){
        char msg[1024];
        sprintf(msg, "%s: Height must match: %d, %d\n", SinkName(), input1->getHeight(), input2->getHeight());
        
        DataFlowException f(SinkName(), msg);
        throw f;
        
    }
    if(input1->getWidth() != input2->getWidth()){
        char msg[1024];
        sprintf(msg, "%s: Widths must match: %d, %d\n", SinkName(), input1->getWidth(), input2->getWidth());
        DataFlowException f(SinkName(), msg);
        throw f;
        
    }
    else{
        //2 inputs same width, output single combined top to bottom
        int wid = 0;
        int heig = input1->getHeight() + input2->getHeight();
        
        if(input1->getWidth() > input2->getWidth()){
            wid = input1->getWidth();
        } else {
            wid = input2->getWidth();
        }
        
        image.setValues(wid, heig);
        image.setData();
        
        for(int i = 0; i < image.getWidth(); i++){
            for(int j = 0; j < input1->getHeight(); j++){
                int index = 3*(j*image.getWidth() + i);
                int oIndex = 3*(j*image.getWidth() + i);
                
                image.getData()[index] = input1->getData()[oIndex];
                image.getData()[index + 1] = input1->getData()[oIndex + 1];
                image.getData()[index + 2] = input1->getData()[oIndex + 2];
            }
        }
        for(int i = 0; i < image.getWidth(); i++){
            for(int j = 0; j < input2->getHeight(); j++){
                int index =  3*((j + input1->getHeight()) * image.getWidth() + i);
                int oIndex =  3*(j * image.getWidth() + i);
                
                image.getData()[index] = input2->getData()[oIndex];
                image.getData()[index + 1] = input2->getData()[oIndex + 1];
                image.getData()[index + 2] = input2->getData()[oIndex + 2];
            }
        }
    }
}


void Blender::Execute()
{
    if(input1 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input1\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input2 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input2\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    else{
        if(percent < 0 || percent > 1){
            char msg[1024];
            sprintf(msg, "%s: Factor are not between 0 and 1: %f\n", SinkName(), percent);
            DataFlowException f(SinkName(), msg);
            throw f;
        }
        //blends img witha  factor
        int width = input1->getWidth();
        int height = input1->getHeight();
        
        image.setValues(width, height);
        image.setData();
        
        
        for(int i = 0; i < image.getHeight(); i++){
            for(int j = 0; j < image.getWidth(); j++){
                int index = 3 * (i * image.getWidth() + j);
                int oIndex = 3 * (i * input1->getWidth() + j);
                
                image.getData()[index] = input1->getData()[oIndex]*(percent) + input2->getData()[oIndex] * (1 - percent);
                image.getData()[index + 1] = input1->getData()[oIndex + 1] * (percent) + input2->getData()[oIndex + 1] * (1 - percent);
                image.getData()[index + 2] = input1->getData()[oIndex + 2] * (percent) + input2->getData()[oIndex + 2] * (1 - percent);
            }
        }
    }
}
    void filters::Update()
    {
        char msg[128];
        struct timeval startTime;
        struct timeval endTime;
        if(input1 != NULL){
            sprintf(msg, "%s: about to update input1\n", FilterName());
            Logger::LogEvent(msg);
            input1->Update();
            sprintf(msg, "%s: done updating input1\n", FilterName());
            Logger::LogEvent(msg);
        }
        if(input2 != NULL){
            sprintf(msg, "%s: about to update input2\n", FilterName());
            Logger::LogEvent(msg);
            input2->Update();
            sprintf(msg, "%s: done updating input2\n", FilterName());
            Logger::LogEvent(msg);
        }
        sprintf(msg, "%s: about execute\n", FilterName());
        Logger::LogEvent(msg);
        gettimeofday(&startTime, 0);
        Execute();
        gettimeofday(&endTime, 0);
        double seconds = double(endTime.tv_sec - startTime.tv_sec)+
        double(endTime.tv_usec - startTime.tv_usec) / 1000000.;
        sprintf(msg, "%s: done executing, took %f\n", FilterName(), seconds);
        Logger::LogEvent(msg);
    }

void Grayscale::Execute(){
    int width = input1->getWidth();
    int height = input1->getHeight();
    image.setValues(width, height);
    image.setData();
    
    
    for(int i = 0; i < image.getHeight(); i++){
        
        for(int j = 0; j < image.getWidth(); j++){
            int index = 3 * (i * image.getWidth() + j);
            int oIndex = 3 * (i * input1->getWidth() + j);
            
            image.getData()[index] = input1->getData()[oIndex]/5 + input1->getData()[oIndex+1]/2 + input1->getData()[oIndex+2]/4;
            image.getData()[index+1] = input1->getData()[oIndex]/5 + input1->getData()[oIndex+1]/2 + input1->getData()[oIndex+2]/4;
            image.getData()[index+2] = input1->getData()[oIndex]/5 + input1->getData()[oIndex+1]/2 + input1->getData()[oIndex+2]/4;

        }
    }
}

void Blur::Execute(){
    int width = input1->getWidth();
    int height = input1->getHeight();
    image.setValues(width, height);
    image.setData();
    
    
    for(int i = 0; i < image.getHeight() ; i++){
        
        for(int j = 0; j < image.getWidth(); j++){
            int index = 3 * (i * image.getWidth() + j);
            int oIndex = 3 * (i * input1->getWidth() + j);
            if(i == 0 || j == 0 || i == image.getHeight() - 1 || j == image.getWidth() - 1){
                image.getData()[index] = input1->getData()[oIndex];
                image.getData()[index+1] = input1->getData()[oIndex+1];
                image.getData()[index+2] = input1->getData()[oIndex+2];
            }else{
                //gets the surrounding pixel colors
                image.getData()[index] = input1->getData()[oIndex - 3]/8 +
                                        input1->getData()[oIndex + 3]/8 +
                                        input1->getData()[oIndex - input1->getWidth()*3 - 3]/8 +
                                        input1->getData()[oIndex - input1->getWidth()*3]/8 +
                                        input1->getData()[oIndex - input1->getWidth()*3 + 3]/8 +
                                        input1->getData()[oIndex + input1->getWidth()*3 - 3]/8 +
                                        input1->getData()[oIndex + input1->getWidth()*3]/8 +
                                        input1->getData()[oIndex + input1->getWidth()*3 + 3]/8;
            
                image.getData()[index+1] = input1->getData()[oIndex - 2]/8 +
                                            input1->getData()[oIndex + 4]/8 +
                                            input1->getData()[oIndex - input1->getWidth()*3 - 2]/8 +
                                            input1->getData()[oIndex - input1->getWidth()*3 + 1]/8 +
                                            input1->getData()[oIndex - input1->getWidth()*3 + 4]/8 +
                                            input1->getData()[oIndex + input1->getWidth()*3 - 2]/8 +
                                            input1->getData()[oIndex + input1->getWidth()*3 + 1]/8 +
                                            input1->getData()[oIndex + input1->getWidth()*3 + 4]/8;
            
                image.getData()[index+2] = input1->getData()[oIndex - 1]/8 +
                                            input1->getData()[oIndex + 5]/8 +
                                            input1->getData()[oIndex - input1->getWidth()*3 - 1]/8 +
                                            input1->getData()[oIndex - input1->getWidth()*3 + 2]/8 +
                                            input1->getData()[oIndex - input1->getWidth()*3 + 5]/8 +
                                            input1->getData()[oIndex + input1->getWidth()*3 - 1]/8 +
                                            input1->getData()[oIndex + input1->getWidth()*3 + 2]/8 +
                                            input1->getData()[oIndex + input1->getWidth()*3 + 5]/8;
            }
        }
    }
}

void Subtract::Execute(){
    if(input1 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input1\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input2 == NULL){
        char msg[1024];
        sprintf(msg, "%s: no input2\n", SinkName());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input1->getHeight() != input2->getHeight()){
        char msg[1024];
        sprintf(msg, "%s: Height must match: %d, %d\n", SinkName(), input1->getHeight(), input2->getHeight());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    if(input1->getWidth() != input2->getWidth()){
        char msg[1024];
        sprintf(msg, "%s: Widths must match: %d, %d\n", SinkName(), input1->getWidth(), input2->getWidth());
        DataFlowException f(SinkName(), msg);
        throw f;
    }
    
    else{
        int width = input1->getWidth();
        int height = input1->getHeight();
        image.setValues(width, height);
        image.setData();
        
        
        for(int i = 0; i < image.getHeight(); i++){
            
            for(int j = 0; j < image.getWidth(); j++){
                int index = 3 * (i * image.getWidth() + j);
                int oIndex1 = 3 * (i * input1->getWidth() + j);
                int oIndex2 = 3 * (i * input2->getWidth() + j);
                
                if(input1->getData()[oIndex1] - input2->getData()[oIndex2] > 0)
                {
                    image.getData()[index] = input1->getData()[oIndex1] - input2->getData()[oIndex2];
                }
                else
                {
                    image.getData()[index] = 0;
                }
                
                if(input1->getData()[oIndex1 + 1] - input2->getData()[oIndex2 + 1] > 0)
                {
                    image.getData()[index+1] = input1->getData()[oIndex1+1] - input2->getData()[oIndex2+1];
                }
                else
                {
                    image.getData()[index+1] = 0;
                }
                
                if(input1->getData()[oIndex1 +2] - input2->getData()[oIndex2+2] > 0)
                {
                    image.getData()[index+2] = input1->getData()[oIndex1+2] - input2->getData()[oIndex2+2];
                }
                else
                {
                    image.getData()[index+2] = 0;
                }
            
            }
        }
    }
}

void Rotate::Execute(){

    int width = input1->getWidth();
    int height = input1->getHeight();
    image.setValues(height, width);
    image.setData2(width, height);


    
    for(int i = 0; i < image.getHeight(); i++){
        
        for(int j = 0; j < image.getWidth(); j++){
            int index = 3 * (i * image.getWidth() + j);
            int oIndex = 3 * ((input1->getHeight()-1 - j) * input1->getWidth() + i);
            
            image.getData()[index] = input1->getData()[oIndex];
            image.getData()[index+1] = input1->getData()[oIndex+1];
            image.getData()[index+2] = input1->getData()[oIndex+2];
        }
    }
}

void Mirror::Execute(){
    
    int width = input1->getWidth();
    int height = input1->getHeight();
    image.setValues(width, height);
    image.setData();
    
    
    for(int i = 0; i < image.getHeight(); i++){
        
        for(int j = 0; j < image.getWidth(); j++){
            int index = 3 * (i * image.getWidth() + j);
            int oIndex = 3 * (i * input1->getWidth() + (input1->getWidth()-1 - j));
            //int oIndex = 3 * (i * input1->getWidth() + j);
            
            image.getData()[index] = input1->getData()[oIndex];
            image.getData()[index+1] = input1->getData()[oIndex+1];
            image.getData()[index+2] = input1->getData()[oIndex+2];
        }
    }
}

void CheckSum::OutputCheckSum(const char * filename) {
    
    if(input1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }
    
    ofstream file;
    file.open(filename, ios::out);
    
    int r = 0;
    int g = 0;
    int b = 0;
    
    for(int i = 0 ; i < input1->getHeight(); i++) {
        for(int j = 0; j < input1->getWidth(); j++) {
            int index = 3 * (i * input1->getWidth() + j);
            
            r += input1->getData()[index];
            g += input1->getData()[index+1];
            b += input1->getData()[index+2];
            
            
            r = r % 256;
            g = g % 256;
            b = b % 256;
        }
    } 
    
    file << "CHECKSUM: " << r << ", " << g << ", " << b << endl;
    file.close();
}




void Color::Execute()
{
    image.setValues(width, height);
    image.setData();
    
    for(int i = 0; i < image.getWidth(); i++){
        
        for(int j = 0; j < image.getHeight(); j++ ){
            int index = 3 * (j * image.getWidth() + i);
            
            image.getData()[index] = red;
            image.getData()[index+1] = green;
            image.getData()[index+2] = blue;
        }
    }
}

//void Color::Update()
//{
//    Execute();
//}

const char * filters::SourceName(){
    return FilterName();
}
    
const char * filters::SinkName(){
    return FilterName();
}




