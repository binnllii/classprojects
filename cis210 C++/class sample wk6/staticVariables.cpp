// This program demonstrates static variables.  The countIt function should increment a counter cumulatively
//every time I call it.  Use static to retain a variable's value after the function call.
// Author: Gayathri Iyer
// Date: 03-Sep-2014
// Sources: None

#include <iostream>
#include <string>

using namespace std;

//function prototype
int countIt();

//main function
int main()
{
	int count = 0;
	//function call first time
	count = countIt();
	cout << count << endl;
	//function call the second time
	count = countIt();
	cout << count << endl;
	//function call the third time.
	count = countIt();
	cout << count << endl;
	char reply;
	cout << "Enter q to quit: ";
	cin >> reply;
	return 0;
}

//function to cumulatively increment count.
int countIt()
{
	static int count = 0;
	count++;
	return count;
}