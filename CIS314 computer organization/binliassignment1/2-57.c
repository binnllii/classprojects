//
//  main.c
//  assignment1
//
//  Created by Bin Li on 1/15/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>


void show_short(short int x);
void show_long(long int x);
void show_double(double x);

int main(){
    //test case
    show_short(1);
    show_long(1);
    show_double(1);
}

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len){
    //print bytes
    int i;
    for(i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("/n");
    
}

void show_short(short int x){
    // byte representations of C objects
    show_bytes((byte_pointer) &x, sizeof(short int));
}

void show_long(long int x){
    //  byte representations of C objects
    show_bytes((byte_pointer) &x, sizeof(long int));
}

void show_double(double x){
    //  byte representations of C objects
    show_bytes((byte_pointer) &x, sizeof(double));
}

