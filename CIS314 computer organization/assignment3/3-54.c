//
//  3-54.c
//  assignment3
//
//  Created by Bin Li on 2/3/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int decode2(int x, int y, int z);

int main(){
    printf("%d", decode2(-4, -8, -12));
    printf("%d", decode2(1, 2, 4));
}
int decode2(int x, int y, int z){
    return (((y-z) << 31) >> 31) ^ (x * (y-z));
    
    //movl 12(%ebp), %edx   y into edx
    //subl 16(%ebp), %edx   computes y-z
    //movl %edx, %eax       y - z into eax
    //sall $31, %eax        (y-z) <<= 31
    //sarl $31, %eax        ((y-z) <<= 31) >> 31
    //imull 8(%ebp), %edx   x * (y-z)
    //xorl %edx, %eax       x * (y-z) ^ ((y-z) <<= 31) >> 31. which is the answer.
}
