//
//  main.c
//  2a
//
//  Created by Bin Li on 4/9/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //open binary file
    FILE *infile = fopen("2B_binary_file.bin", "r");
    
    //read binary file into array
    //fread(destination, size of chunk, number of chunks, file_str)
    int A[100];
    fread(A, sizeof(int) * 25, 4, infile);
    
    //print refult of terminal
    for(int i = 0; i < 100; i++){
        printf("A[%d]: %d\n", i, A[i]);
        
    }
    fclose(infile);
}
