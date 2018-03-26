// This program demonstrates default parameters
// Author: Gayathri Iyer
// Date: 03-September-2014
// Sources: None

#include <iostream>
#include <string>

using namespace std;

//function prototypes
void printIt(string message = "Hello World!!");

int main()
{
	printIt("Hello from GD Iyer");
	printIt();

	char reply;
	cout << "Enter q to quit: ";
	cin >> reply;
	return 0;
}

void printIt(string message)
{
	cout << message << endl;
}