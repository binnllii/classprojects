//
//  main.c
//  assignment7
//
//  Created by Bin Li on 3/8/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>
#include <time.h>


#define VECTOR_SIZE 100000000
typedef long long data_t;
typedef data_t *vec_ptr;
void inner4(vec_ptr u, vec_ptr v, data_t *dest);
void inner5(vec_ptr u, vec_ptr v, data_t *dest);
#include <time.h>




int main(int argc, const char * argv[]) {
    vec_ptr v1 = (vec_ptr) malloc(sizeof(data_t) * (VECTOR_SIZE));
    vec_ptr v2 = (vec_ptr) malloc(sizeof(data_t) * (VECTOR_SIZE));
    data_t *data = (data_t *) calloc(VECTOR_SIZE, sizeof(data_t));
    // insert code here...
    clock_t t1, t2;
    
    
    t1 = clock();
    
    inner4(v1,v2,data);
    
    t2 = clock();
    

    //printf("%lu", (t2*1000)-(t1*1000));
    printf("%f milliseconds for inner4 \n",((double)t2 - t1) / CLOCKS_PER_SEC *1000);

    
    
    
    return 0;
}


data_t * get_vec_start(vec_ptr v) {
    return v;
}

int vec_length(vec_ptr v) {
    return VECTOR_SIZE;
}



//#1
void inner4(vec_ptr u, vec_ptr v, data_t *dest) {
    
    long int i;
    int length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t) 0;
    
    for (i = 0; i < length; i++){
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}




