

#include <exception>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "logging.h"

using namespace std;

ofstream Logger::logger("logger.txt");

DataFlowException::DataFlowException(const char *type, const char *error){
    sprintf(msg, "Throwing exception: (%s), %s", type, error);
    Logger::LogEvent(msg);
}



void Logger::Finalize(){
    logger.close();
}

void Logger::LogEvent(const char *event){
    logger << event << endl;
}
