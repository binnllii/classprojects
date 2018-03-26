//
//  3-69A.c
//  assignment4
//
//  Created by Bin Li on 2/13/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>

typedef struct ELE *tree_ptr;

long trace(tree_ptr);


struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
};

int main(){
    tree_ptr TP;
    TP->val = 100;
    TP->left = NULL;
    TP->right = NULL;
    trace(TP);
}

long trace(tree_ptr tp){
    long val = 0;
    if(tp){
        return 0;
    }
    while(tp){
        tp = tp->left;//traverses left until null
        val = tp->val;
    }
    return val;
    //returns the leftmost value
}
//b. This functions returns the value of the most leftmost node
