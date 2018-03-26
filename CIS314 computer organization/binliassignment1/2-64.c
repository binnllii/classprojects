//
//  main.c
//  assignment1
//
//  Created by Bin Li on 1/15/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>



int any_odd_one(unsigned x);


int main(){
    //test cases
    printf("%X/n", any_odd_one(0x0));
    printf("%X/n", any_odd_one(0x1));
    printf("%X/n", any_odd_one(0x3));
    printf("%X/n", any_odd_one(0xFFFFFFFF));
    printf("%X/n", any_odd_one(0x55555555));

}


int any_odd_one(unsigned x){
    // Since A is 1010, when you multply x with A the 1's are already assigned to the odd bit
    // therefore when you say it id not equal to zero, it will return a 1 when any odd bit x equals one
    return ((x & 0xAAAAAAAA) != 0);
}



