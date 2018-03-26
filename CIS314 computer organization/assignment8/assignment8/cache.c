//
//  main.c
//  assignment8
//
//  Created by Bin Li on 3/16/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef unsigned char *byte_pointer;


typedef struct {
    unsigned char valid;
    unsigned int tag;
    unsigned int value;
} block;



unsigned getByte(unsigned value, int b){
    unsigned shift = b * 8;
    unsigned mask = (0xff << shift);
    unsigned bit = (value & mask) >> shift;
    
    return bit;
}

void showBytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
    
    printf("%.2x", start[i]);
    printf("\n");
}


void splitAddress(unsigned address, unsigned* aParts){
    // Split address into 3 parts and puts into unsigned array
    aParts[0] = address >> 6;           // 26 tags
    aParts[1] = (address << 26) >> 28;  // 4 sets
    aParts[2] = (address << 30) >> 30;  // 2 blocks
}


void print(block* cache, int length){
    for (int i = 0; i < length; i++){
        block line = cache[i];
        if (line.valid){
            printf("Set: %d - tag: %x - valid: %x - value: ", i, line.tag, line.valid);
            showBytes((byte_pointer) &line.value, sizeof(unsigned));
        }
    }
}


//write to cache
void writeCache(block* cache, unsigned address, unsigned value, unsigned* aParts){
    splitAddress(address, aParts);
    
    block line = cache[aParts[1]];
    if (line.valid){
        printf("Evicting block - set: %x - tag: %x - valid: %x - value: ", aParts[1], line.tag, line.valid);
        showBytes((byte_pointer) &line.value, sizeof(unsigned));
    }
    
    printf("Wrote set: %x - tag: %x - valid: %x - value: ", aParts[1], aParts[0], 1);
    showBytes((byte_pointer) &value, sizeof(unsigned));
    cache[aParts[1]].valid = 1;
    cache[aParts[1]].tag = aParts[0];
    cache[aParts[1]].value = value;
}

//reads whats in the cache
void readCache(block* cache, unsigned address, unsigned* aParts){
    splitAddress(address, aParts);
    block line = cache[aParts[1]];
    
    unsigned bitValue = getByte(line.value, aParts[2]);
    
    printf("Looking for set: %x - tag: %x\n", aParts[1], aParts[0]);
    if (line.valid && aParts[0] == line.tag){
        printf("Found set: %x - tag: %x - valid: %x - value: %x\n", aParts[1], line.tag, line.valid, bitValue);
        
        printf("Hit!\n");
    }
    else {
        if (!line.valid){
            printf("No valid set found. Missed!\n");
        }
        else {
            printf("Found set: %x - tag: %x - valid: %x - value: %x\n", aParts[1], line.tag, line.valid, bitValue);
            printf("Tags do not match. Missed\n");
        }
    }
}






int main(int argc, char const *argv[]){
    int len = 16;
    //allocate memory to cache
    block* cache = malloc(len * sizeof(block));
    for (int i = 0; i < len; i++){
        cache[i].valid = 0;
    }
    
    unsigned aParts[3];
    char input;
    unsigned address;
    unsigned val;
    int proceed = 1;
    while (proceed){
        printf("%s", "Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
        scanf("%s", &input);
        
        switch (input){
        case 'r':
            printf("%s", "Enter 32-bit unsigned hex address: ");
            scanf("%x", &address);
            readCache(cache, address, aParts);
            printf("\n");

            break;
            
        case 'w':
            printf("%s", "Enter 32-bit unsigned hex address: ");
            scanf("%x", &address);
            printf("%s", "Enter 32-bit unsigned hex value: ");
            scanf("%x", &val);
            writeCache(cache, address, val, aParts);
            printf("\n");
            
            break;
            
        case 'p':
            print(cache, len);
            printf("\n");
            break;
            case 'q':
            proceed = 0;
            printf("\n");
            
            break;
        }
    }
}
