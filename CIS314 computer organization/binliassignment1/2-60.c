//
//  main.c
//  assignment1
//
//  Created by Bin Li on 1/15/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>


unsigned replace_byte (unsigned x, int i, unsigned char b);

int main(){
    // test case
    printf("%X/n", replace_byte(0x12345678, 2, 0xAB));
    printf("%X/n", replace_byte(0x12345678, 0, 0xAB));

}

unsigned replace_byte(unsigned x, int i, unsigned char b){
    // shifts b to the left by 2 * i positions
    int shift = (b << (8 * i));
    //masks the numbers by 2 * i positions/ replaces with FF
    int mask = 0xff << (8 * i);
    //returns the not mask & x or shift
    //when put together only the ab and numbers 12345678 will be returned.
    return (~mask & x) | shift;
}



