//
//  2-71.c
//  assignment2
//
//  Created by Bin Li on 1/27/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//
#include <stdio.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    //shift word to the left by (3 - bytenum) * 8 values
    // Then shift to the right 24 values
    int byte = (int) word << ((3 - bytenum) << 3) >> 24;
    /* sign extend to 32 bit int(signed) */
    return byte;
    //correct implimentation.
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%X/n",(xbyte(0x8833AA99, 2)));
    }

//whats wrong with the code?
//It doesnt return a 32 bit int
