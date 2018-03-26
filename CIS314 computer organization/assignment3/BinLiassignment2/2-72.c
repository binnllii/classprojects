//
//  2-72.c
//  assignment2
//
//  Created by Bin Li on 1/27/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//
#include <stdio.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes > 0 && maxbytes >= sizeof(val))
        memcpy(buf, (void *) &val, sizeof(val));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 3;
    int array[5];
    copy_int(a, array, 5);	//this should get in to the if statement
    copy_int(a, array, 3);	//this should FAIL to get in to the if statement
    return 0;
}

//Explain why the conditional test in the code always succeeds. Hint: The sizeof
//operator returns a value of type size_t.
//The comparison of unsigned expression with >= 0 is always going to return true.
//maxbytes is signed, sizeof(val) is unsigned, combine them it returns unsigned.
