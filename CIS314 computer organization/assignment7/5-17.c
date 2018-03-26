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
    clock_t t3, t4;

    t3 = clock();
    
    inner5(v1,v2,data);
    
    t4 = clock();
    //printf("%lu", (t2*1000)-(t1*1000));

    printf("%f milliseconds for inner6 \n",((double)t4 - t3) / CLOCKS_PER_SEC *1000);
    
    
    
    return 0;
}


data_t * get_vec_start(vec_ptr v) {
    return v;
}

int vec_length(vec_ptr v) {
    return VECTOR_SIZE;
}


//#3
void inner6(vec_ptr u, vec_ptr v, data_t *dest)
{
    long int i;
    long int length = vec_length(u);
    long int limit = length-3;
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t) 0;
    data_t sum1 = (data_t) 0;
    data_t sum2 = (data_t) 0;
    data_t sum3 = (data_t) 0;
    
    //unrolls 4 at a time
    for (i = 0; i < limit; i += 4) {
        sum += (udata[i] * vdata[i]);
        sum1 += (udata[i+1] * vdata[i+1]);
        sum2 += (udata[i+2] * vdata[i+2]);
        sum3 += (udata[i+3] * vdata[i+3]);
    }
    for (; i < limit; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    
    *dest = sum + sum1 + sum2 + sum3;
}
