/* This program demonstrates how to create your own tools by using functions.
   You can extend this tool box to include readChar, readFloat etc 
   to make your own standard input library.

   Written by: Li Liang
   Date: 09/20/2009

   Sources: None
*/

#include <iostream>                 
#include <string>                   

using namespace std;                

//function prototypes
int readInt(const char prompt[]);
void readString (const char prompt[], char inputStr[], int maxChar);

//named constants
const int MAX_CHAR = 101;

int main ()
{
	int		age;
	char	name[MAX_CHAR];

	//catch the returned value of readInt
	age = readInt("Please enter your age: ");
	cout << endl << age << " is cool!" << endl;

	//pass "name" in as a place holder for the input string
	readString("Please enter your name: ", name, MAX_CHAR);
	cout << endl << "Hello " << name << "!" << endl;
    
    return 0;
}

/* This function reads an integer from the standard input.
   in: prompt
   return: a legal integer
*/
int readInt(const char prompt[])
{
	int		intVal;

	//prompt user for input
	cout << endl << prompt;
	cin >> intVal;

	//check if a valid integer is entered
	while (!cin)
	{
		//clear the error code for cin so that it can work again
		cin.clear();

		//throw away the garbage entered, e.g "None of your business."
		cin.ignore(100, '\n');

		//kindly ask again
		cout << "You've entered an illegal integer. Please try again: ";
		cin >> intVal;
	}

	//throw the rest of the line away, e.g. "99 Yippeeeeeee!"
	cin.ignore(100, '\n');

	return intVal;
}

/* This function reads a c-string from the standard input.
   in: prompt
       maxChar: at most maxChar-1 characters can be stored. The rest of the input will be discarded.
   out: inputStr
   return: none
*/
void readString (const char prompt[], char inputStr[], int maxChar)
{
	cout << endl << prompt;

	//read until it either reaches the maxChar limit or encounters a '\n'
	cin.get(inputStr, maxChar, '\n');
	while(!cin)
	{
		cin.clear ();
		cin.ignore (100, '\n');
		cout << endl << prompt;
		cin.get(inputStr, maxChar, '\n');
	}

	//throw away the '\n'
	cin.ignore (100, '\n');
}