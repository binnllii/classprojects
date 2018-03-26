    // sources: http://www.cplusplus.com/forum/beginner/158766/
//  main.cpp
//  lab8b
//
//  Created by Bin Li on 5/24/16.
//  Copyright © 2016 Bin Li. All rights reserved.
//

/*Write	a program that prompts the	user to	input a	string.	You	MUST use char arrays to	store your string.	Do	not	use	string.	Your program should	convert	the	message	to	upper-case	letters, substitute	digits	for	certain	letters	(A->4,	B->8,	E->3,	I->1,	O->0, S->5), and the append 10 or so exclamation	marks. Hint: Store the original message in	char array,	and	then go	back through the array, translating and printing characters one by one.*/
 
 
//ask user to inpur string using char arrays.
//convert msg into upper-case letters
//substitute digits

#include <iostream>
#include <cctype>

char decode(char m);
int main()
{
    //variables
    const int MAXCHAR = 100; //set constant of max characters that will get decoded
    char eString[MAXCHAR]; //set the array with the max characters that can be entered
    int i;
    std::cout << "Enter a string: "; //gets user input
    std::cin.getline(eString, MAXCHAR); //stores user input able to include spaces in text using cin.getline
    //using user input, it goes through this forloop.
    for((i = 0); eString[i] != 0; i++) //goes through every letter up to MAXCHAR
    {
        std::cout << decode(eString[i]); //runs this function for every letter entered by the user
    }
    std::cout << "!!!!!!!!!!" << std::endl;
    return 0;
}

//Decode function
char decode(char m)

{
    m = std::toupper(m); //every letter to uppercase
    //switch statement changes certain letters to numbers
    switch(m)
    {
        case 'A' : return '4';
        case 'B' : return '8';
        case 'E' : return '3';
        case 'I' : return '1';
        case 'O' : return 'O';
        case 'S' : return '5';
        default: return m;
            
        
    }
}

