//
//  2-83.c
//  assignment2
//
//  Created by Bin Li on 1/27/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//
#include <stdio.h>

unsigned f2u(float f);

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    
    /* Give an expression using only ux, uy, sx, and sy */
    
    //return uy;
    //if the first argument is less than the second argument, return a 1
    return (uy << 1 == 0 && ux << 1 == 0) || // for when Both are zeros
    (sy == 0 && sx == 1) ||       // for when x >= 0, y < 0
    (!sy && !sx && uy >= ux) ||   // for when x >= 0, y >= 0
    (sy && sx && uy <= ux);       // for when x < 0, y < 0
}

unsigned f2u(float f) {
    return *((unsigned*) & f);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%X\n",float_le(0, 0));
    //1
    printf("%X\n",float_le(-5, 5));
    //1
    printf("%X\n",float_le(12.375, 11.375));
    //0
}
