// This program demonstrates local and file scope
// Author: Gayathri Iyer
// Date: 03-September-2014
// Sources: None

#include <iostream>
#include <string>

using namespace std;

//function prototypes
void doIt();

// This declaration of x is at file scope or global
int x = 0;

int main()
{
	//local x and it can be seen only in main
	int y = 0;
	y = 10;
	cout << "x before call to doIt is " << x << endl;
	doIt();
	cout << "x  after call to doIt is " << x << endl;
	char reply;
	//empty blocks
	{
		int x = 20;
		cout << "x inside block = " << x << endl;
	}

	cout << "x  after the block " << x << endl;
	//for loops
	for (int i = 0; i < 5; i++)
	{
		//do something
	}

	cout << "Enter q to quit: ";
	cin >> reply;
	return 0;
}

void doIt()
{
	//x is local to the function
	int x;
	x = 20;
}