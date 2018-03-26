// This program is similar to your assignment 4.
// It demos how to echo the input, check for conditions and how to rewind the file to 
// go back to the beginning.
// Written by: Gayathri Iyer
// Sources: None
// Date: 06/29/2014

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main ()
{
	// Declarations
	string inputFileName;
	string name, college;
	double score = 0, totalPSU = 0;
	int psuCount = 0;
	ifstream inputFile;

	cout << "Input file name: ";
	getline(cin, inputFileName);

	// Open the input file.
	inputFile.open(inputFileName);	// Need .c_str() on a mac to convert a C++ string to a C-style string

	// The next line can be used instead of the preceding if the file name is "hard coded" in the program.
	// This saves a lot of time typing in the file name over and over while you are debugging.
	// inputFile.open("C:\\CS161\\Demo\\text.txt");		// Need \\ to represent a single '\'
	
	// Check the file opened successfully.
	if ( !inputFile.is_open())
	{
		cout << "Unable to open input file." << endl;
		exit(1);
	}
	
	// This section reads and echo's the file one line at a time.
	while (inputFile.peek() != EOF)
	{
		inputFile >> name >> college >> score;
		cout << left << setw(15) << name << setw(10) << college << setw(8) << score << endl;
	}
	cout << "\nEnd of file reached\n" << endl;
	
	// Must clear the end-of-file flag to be able to rewind and re-read from the beginning.
	inputFile.clear();
	// 'Rewind' the input stream to the beginning - i.e. byte 0
	inputFile.seekg(0);

	// Now read the file one token at a time and calculate the average of psu students	
	while (inputFile >> name)
	{
		inputFile >> college >> score;
		if (college == "PSU")
		{
			totalPSU += score;
			psuCount++;
		}
	}
	cout << "\nEnd of file reached\n" << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Average of PSU students = " << totalPSU / psuCount << endl;
	
	// Close the input file stream
	inputFile.close();
	
	return 0;	
}

"/Users/BinLi/Desktop/cis210/lab3/lab3/Ch3_Ex6Data.txt
