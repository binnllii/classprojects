//This program demos basic arrays
//Gayathri Iyer
//05-September-2014
//Sources:none
#include <iostream>

using namespace std;

//global constants
const int CAP = 10;

int main()
{
	int list[CAP] = {0}, i = 0;

	//read from user into list
	cout << "Enter 10 whole numbers:";

	for(i = 0; i < CAP; i++)
		cin >> list[i];

	//output to user forwards
	cout << "List printed forwards:\n";
	for(i = 0; i <= CAP; i++)
		cout << list[i] << " ";
	cout << endl;

	//output to user backwards
	cout << "List printed backwards:\n";
	for(i = CAP-1; i >= 0; i--)
		cout << list[i] << " ";
	cout << endl;

	return 0;
}
