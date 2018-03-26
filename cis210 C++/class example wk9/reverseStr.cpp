//This code demos char arrays, some functions and how to reverse a string
//This program demos char arrays
//Gayathri Iyer
//10-September-2014
//Sources:None
#include <iostream>

using namespace std;

//global constants
const int MAXCHAR = 101;

//function prototype
int mystrlen(char msg[]);

int main()
{
	char msg[MAXCHAR];
	string name;
	int length = 0, i = 0;
	//assignment operator can be used with strings
	name = "John Smith";
	//must use strcpy to put a value into msg which is a cstring
	strcpy_s(msg, "This is a test");

	//msg gets overwritten from the user
	cout << "Enter a message:";
	cin.get(msg, MAXCHAR);
	length = mystrlen(msg);
	//print the string in reverse
	for(i = length-1; i >= 0; i--)
		cout << msg[i];
	cout << endl;

	return 0;
}

//function to find string length
int mystrlen(char msg[])
{
	int count = 0, i = 0;
	while(msg[i++] != '\0')
		count++;
	return count;
}