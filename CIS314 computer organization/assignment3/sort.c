//
//  main.c
//  assignment3
//
//  Created by Bin Li on 1/31/17.
//  Copyright © 2017 Bin Li. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>


int main(int argc, const char * argv[]) {
    unsigned long number;
    int position, d, swap, c, arrayNum, *array;
    printf("Enter an Integer Array Length: "); //prompt user to enter array length
    scanf("%ld", &number); // user input with long unsigned type
    array = (int *) malloc(sizeof(int) *number); //create array using malloc
    
    //Array to ask for user input to populate the array
    for(c = 0; c < number; c++){
        printf("Enter the ");
        printf("%d", c + 1);
        printf("/");
        printf("%lu", number);
        printf(" numbers for the the array: ");
        scanf("%d", &arrayNum);
        array[c] = arrayNum;
        
        
    }
    
    //sort the numbers in the array using seleciton sort
    for (c = 0; c < (number - 1); c++){
        position = c;
        for (d = c + 1; d < number; d++){
            if (array[position] > array[d])
                position = d;
        }
        if (position != c){
            swap = array[c];
            array[c] = array[position];
            array[position] = swap;
        }
    }
    //interate through and print the array
    printf("Sorted list in ascending order:\n");
    for (int c = 0 ; c < number ; c++ )
        printf("%d\n", array[c]);
    //free the array
    free(array);
    return 0;
}

