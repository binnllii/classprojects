//
//  main.c
//  assignment4
//
//  Created by Bin Li on 2/13/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>



#define M 13
//declare 
typedef int Marray_t[M][M];



void transpose(Marray_t A){
    int i, a;
    
    for(i = 0; i < M; i++){
        //use pointers for ap1 and ap2
        int *ap1 = &A[i][0];
        int *ap2 = &A[0][i];
        
        for(a = 0; a < i; a++){
            //swaps and increments pointers
            int t = *ap1;
            *ap1 = *ap2;
            *ap2 = t;
            ap1++;
            ap2 += M;
        }
    }
}



int main() {
    // insert code here...
    //populates the array
    Marray_t arr = {{1,2,3,4,5}, {1,2,3,2,1}, {5,4,3,1,2},{5,4,3,9,2},{4,4,3,1,2}};
    int i, a;
    //for loop to print out matrix
    for(i = 0; i < M; i++){
        for(a = 0; a < M; a++){
            printf("%d", (unsigned)arr[i][a]);
        }
        printf("\n");
    }
    printf("\n");
}





