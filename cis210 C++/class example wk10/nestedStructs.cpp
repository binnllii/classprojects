//This program demos simple structs using studentType
#include <iostream>
#include <string>
using namespace std;

//define the Address struct
struct Address
{
	string streetName;
	string doorNum;
	string city;
	string zip;
	string state;
};

//defines the Date struct
struct Date
{
	int day;
	int month;
	int year;
};

//define of the struct studentType
struct StudentType
{
	string fname;
	string lname;
	string stdID;
	Address stdAddress;
	double GPA;
	Date joinDate;
	Date quitDate;
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
	cout << "Enter student's address (street name):";
	getline(cin, pccStd.stdAddress.streetName);
	cout << "Enter student's address (door number):";
	getline(cin, pccStd.stdAddress.doorNum);
	cout << "Enter student's address (city):";
	getline(cin, pccStd.stdAddress.city);
	cout << "Enter student's GPA:";
	cin >> pccStd.GPA;

	psuStd = pccStd;

	cout << psuStd.fname << endl;
	cout << psuStd.lname << endl;
	cout << psuStd.stdAddress.doorNum << endl;
	cout << psuStd.stdAddress.streetName << endl;
	cout << psuStd.stdAddress.city << endl;
	cout << psuStd.stdID << endl;
	cout << psuStd.GPA << endl;

	return 0;
}




