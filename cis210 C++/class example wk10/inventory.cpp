//This program demos structs using InventoryType
//The text file has a model number and a bin number for an Inventory database
//Another example for assignment 6
//Gayathri Iyer
//15-September, 2014
//Sources: None

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//global constants
const int CAP = 100;
const int MAXCHAR = 101;

//define of the struct InventoryType

struct InventoryType
{
	string modelNo;
	string binNo;
};

//function prototype
void openFile(ifstream &inFile);
void displayMenu();
char readInput();
void exeCommand(char option, InventoryType storeroom[], int size);
int readData(ifstream &inFile, InventoryType storeroom[]);
void searchModel(InventoryType storeroom[], int size);
void searchBin(InventoryType storeroom[], int size);
void outputData(InventoryType storeroom[], int size);

//main
int main()
{
	InventoryType storeroom[CAP];
	int size = 0;
	char option;
	ifstream inFile;
	openFile(inFile);
	size = readData(inFile, storeroom);
	outputData(storeroom, size);
	do
	{
		displayMenu();
		option = readInput();
		exeCommand(option, storeroom, size);
	}while(tolower(option) != 'q');
	
	return 0;
}

//open file
void openFile(ifstream &inFile)
{
	char filename[MAXCHAR];
	cout << "Enter filename:";
	cin.get(filename, MAXCHAR);
	cin.ignore(100, '\n');
	inFile.open(filename);
	if(!inFile)
	{
		cout << "File did not open! Program terminating!!";
		exit(0);
	}
}

//display menu to user
void displayMenu()
{
	cout << "Please pick one of the options:" << endl;
	cout << "(m) to search by model number:" << endl;
	cout << "(b) to search by bin number:" << endl;
	cout << "(q) to quit:" << endl;
}

//read input from user after displaying the menu
char readInput()
{
	char option;
	cin.get(option);
	cin.ignore(100, '\n');
	return option;
}

//execute the command based on user input
void exeCommand(char option, InventoryType storeroom[], int size)
{
	switch(tolower(option))
	{
	case 'm':
		searchModel(storeroom, size);
		break;
	case 'b':
		searchBin(storeroom, size);
		break;
	case 'q':
		exit(0);
		break;
	default:
		cout << "Illegal input!";
	}
}
//read data from file and 
int readData(ifstream &inFile, InventoryType storeroom[])
{
	int size = 0;
	while(!inFile.eof())
	{
		inFile >> storeroom[size].modelNo >> storeroom[size].binNo;
		size++;
	}
	return size;
}

//print the contents of the array
void outputData(InventoryType storeroom[], int size)
{
	for(int i = 0; i < size; i++)
		cout << setw(10) << left << storeroom[i].modelNo 
			 << setw(10) << storeroom[i].binNo << endl;
}

//search by Model Number
void searchModel(InventoryType storeroom[], int size)
{
	string srchStr;
	bool found = false;
	cout << "Enter model number to search for:";
	getline(cin, srchStr);
	for(int i = 0; i < size; i++)
	{
		if(storeroom[i].modelNo == srchStr)
		{
			cout << setw(10) << left << storeroom[i].modelNo 
			 << setw(10) << storeroom[i].binNo << endl;
			found = true;
			break;
		}
	}
	if(!found)
		cout << "Model not found!!" << endl;
}

//search by Bin Number
void searchBin(InventoryType storeroom[], int size)
{
	string srchStr;
	bool found = false;
	cout << "Enter bin number to search for:";
	getline(cin, srchStr);
	for(int i = 0; i < size; i++)
	{
		if(storeroom[i].binNo == srchStr)
		{
			cout << setw(10) << left << storeroom[i].modelNo 
			 << setw(10) << storeroom[i].binNo << endl;
			found = true;
			break;
		}
	}
	if(!found)
		cout << "Bin not found!!" << endl;
}


