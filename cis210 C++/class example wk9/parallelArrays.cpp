//This program demos parallel arrays using Programming Ex #7
//Gayathri Iyer
//10-September-2014
//Sources:None

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//global constants
const int CAP = 100;
const int MAXCHAR = 101;

//function prototype
void openFile(ifstream &inFile);
int readData(ifstream &inFile, string names[], int votes[]);
void calculateTotal(int size, string names[], int votes[]);


int main()
{
	string names[CAP];
	int votes[CAP] = {0};
	int size = 0;

	ifstream inFile;
	//open file
	openFile(inFile);
	//read from file
	size = readData(inFile, names, votes);
	//calculate total and percentage for each candidate
	calculateTotal(size, names, votes);
	return 0;
}

//open file
void openFile(ifstream &inFile)
{
	char filename[MAXCHAR];
	cout << "Enter filename:";
	cin.get(filename, MAXCHAR);
	inFile.open(filename);
	if(!inFile)
	{
		cout << "File did not open! Program terminating!!";
		exit(0);
	}
}


//read from file
int readData(ifstream &inFile, string names[], int votes[])
{
	int size = 0;
	while(!inFile.eof())
	{
		inFile >> names[size] >> votes[size];
		size++;
	}
	return size;
}

//calculate total and percentages
void calculateTotal(int size, string names[], int votes[])
{
	int total = 0;
	double percent = 0;
	for(int i = 0; i < size; i++)
		total += votes[i];
	for(int i =0; i < size; i++)
	{
		percent = (static_cast<double>(votes[i])/total) * 100;
		cout << fixed << showpoint << setprecision(2);
		cout << left << setw(15) << names[i] << setw(8) << votes[i] 
			 << setw(5) << percent << "%" << endl;
	}
}