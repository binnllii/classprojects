#include "image.h"
#include "filters.h"
#include "sink.h"
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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
                int oIndex = 3 * ((i * input2->getWidth() + j) - input1->getWidth());
                image.getData()[index] = input2->getData()[oIndex];
                image.getData()[index + 1] = input2->getData()[oIndex + 1];
                image.getData()[index + 2] = input2->getData()[oIndex + 2];
			}
		}
	}
}

void TBConcat::Execute()
{
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


void Blender::Execute()
{
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

void filters::Update()
{
    if(input1 != NULL){
        input1->Update();
        Execute();
    }
    if(input2 != NULL){
        input2->Update();
        Execute();
    }
}


