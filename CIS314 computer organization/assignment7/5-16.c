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
    clock_t t2, t3;
    
    

    
    t2 = clock();
    
    inner5(v1,v2,data);
    
    t3 = clock();
    

    //printf("%lu", (t2*1000)-(t1*1000));

    printf("%f milliseconds for inner5 \n",((double)t3 - t2) / CLOCKS_PER_SEC *1000);

    
    
    
    return 0;
}


data_t * get_vec_start(vec_ptr v) {
    return v;
}

int vec_length(vec_ptr v) {
    return VECTOR_SIZE;
}







//#2
void inner5(vec_ptr u, vec_ptr v, data_t *dest)
{
    long int i;
    long int length = vec_length(u);
    long int limit = length-3;
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t) 0;
    
    
    //unrolls 4 at a time
    for (i = 0; i < limit; i += 4) {
        sum += (udata[i] * vdata[i]);
        sum += (udata[i+1] * vdata[i+1]);
        sum += (udata[i+2] * vdata[i+2]);
        sum += (udata[i+3] * vdata[i+3]);
    }
    for (; i < limit; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    
    *dest = sum;
}
