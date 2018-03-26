//
//  main.c
//  assignment1
//
//  Created by Bin Li on 1/15/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>

int lower_one_mask(int n);

int main(){
    // the %d will return a number for the 5 input instead of 1F.
    printf("%d/n", lower_one_mask(1));
    printf("%d/n", lower_one_mask(2));
    printf("%d/n", lower_one_mask(3));
    printf("%d/n", lower_one_mask(5));
}


int lower_one_mask(int n){
    //the number 2 is 0010 and it gets shifted to the left by (n-1) it masks the n 1's this shift makes the input of 0 not work.
    //the -1 in the end compensates for the extra shift in the equation.
    return (2 << (n - 1)) - 1;
}


