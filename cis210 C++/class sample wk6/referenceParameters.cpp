// This program demonstrates reference parameters
// Author: Gayathri Iyer
// Date: 03-September-2014
// Sources: None

#include <iostream>
#include <string>
using namespace std;

void doIt(int &p);

int main()
{
	int x = 0;
	x = 10;
	cout << "x before call to doIt is " << x << endl;
	doIt(x);
	cout << "x after call to doIt is " << x << endl;
	char reply;
	cout << "Enter q to quit: ";
	cin >> reply;
	return 0;
}

//function doIt
void doIt(int &p)
{
	p = 20;
}
