//This program demos char arrays
//Gayathri Iyer
//10-Septemeber-2014
//sources:None
#include <iostream>

using namespace std;

//global constants
const int MAXCHAR = 101;

int main()
{
	char name[MAXCHAR];
	cout << "Enter your name (100 characters):";
	cin.get(name, MAXCHAR);

	cout << "Your name is " << name << endl;

	return 0;
}
