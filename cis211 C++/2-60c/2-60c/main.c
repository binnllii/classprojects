//
//  main.c
//  2-60c
//
//  Created by Bin Li on 1/19/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>

unsigned replace_byte (unsigned x, int i, unsigned char b);

int main(){
    //printf("%u", replace_byte(0x12345678, 2, 0xAB));
    int a = 0xAB;
    printf("%x/n", a << 8);
}



unsigned replace_byte(unsigned x, int i, unsigned char b){
    int shift = (b << (8 * i));
    int mask = 0xff << shift;
    return (mask & x) | shift;
}

