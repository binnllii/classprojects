#include "sink.h"
#include "image.h"
void Sink::SetInput(Image * input1){
    this->input1 = input1;
}

void Sink::SetInput2(Image * input2){
    this->input2 = input2;
}

Sink::Sink(){
    input1 = NULL;
    input2 = NULL;
};
