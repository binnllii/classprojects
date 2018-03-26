#include "image.h"
#include "filters.h"
#include "sink.h"
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logging.h"
#include <exception>

using namespace std;


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

void Blender::SetFactor(float percent)
{
    this->percent = percent;
}

void Shrinker::Execute()
{
    //outputs half width half height
    int halfWid = input1->getWidth() / 2;
    int halfHeig = input1->getHeight() / 2;
    
    //	image.setValues(halfWid, halfHeig);
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
//        msg << "Height must match " << SinkName() << " " << input1->getHeight() << " " << input2->getHeight());
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
        
        if(input1->getHeight() > input1->getHeight()){
            heig = input2->getHeight();
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
                    int oIndex = 3 * (i * input2->getWidth() + j);
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
        //2 inputs same width, output single sombined top to bottom
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
        Execute();
        sprintf(msg, "%s: done executing\n", FilterName());
        Logger::LogEvent(msg);
    }

    const char * filters::SourceName(){
        return FilterName();
    }
    
    const char * filters::SinkName(){
        return FilterName();
    }


