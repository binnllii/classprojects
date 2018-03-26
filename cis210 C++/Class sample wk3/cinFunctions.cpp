//This program demos cin.get(), getline(), and cin.ignore(100, '\n');
//Also in the process, demos reading strings with spaces
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name = " ";
	string subject = " ";
	char reply = ' ';
	//user input
	cout << "Please enter your full name:";
	getline(cin, name);
	//echo the input
	cout << "You entered:" << name << endl;
	cout << "Is this correct (y/n):";
	cin.get(reply);
	cin.ignore(100, '\n');
	cout << "PLease enter your subject:";
	getline(cin, subject);
	//echo the input
	cout << "You entered:" << subject << endl;

	return 0;
}