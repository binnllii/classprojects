//This program demos simple structs using studentType
//Gayathri Iyer
//15-September-2014
//Sources: None

#include <iostream>
#include <string>
using namespace std;

//define the struct studentType

struct StudentType
{
	string fname;
	string lname;
	string stdID;
	string address;
	double GPA;
};

//main
int main()
{
	StudentType pccStd, psuStd;
	//read user input for pccStd
	cout << "Enter student's first name:";
	getline(cin, pccStd.fname);
	cout << "Enter student's last name:";
	getline(cin, pccStd.lname);
	cout << "Enter student's ID number:";
	getline(cin, pccStd.stdID);
	cout << "Enter student's address:";
	getline(cin, pccStd.address);
	cout << "Enter student's GPA:";
	cin >> pccStd.GPA;

	psuStd = pccStd;

	cout << psuStd.fname << endl;
	cout << psuStd.lname << endl;
	cout << psuStd.address << endl;
	cout << psuStd.stdID << endl;
	cout << psuStd.GPA << endl;

	return 0;
}




