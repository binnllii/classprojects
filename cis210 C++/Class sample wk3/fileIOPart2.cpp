/*This program demos file input output.  inData.txt file has 4 lines of data.  The first line contains the person's 
first name, last name, and dept.  The second line contains the monthly salary and bonus as a percent. The third line 
has the distance travelled and the traveling time in hours.  The last line has the number of coffee mugs sold and 
the price per cup.  Write a program that calculates the total salary, the average speed and the total sales amount.
Your program should work such that if the input file changes, the output should change without having to reedit the 
program. Output your results to the console and a file called outData.txt */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
/Users/BinLi/Desktop/fileIOPart2.cpp
int main()
{
	//variables
	//to read from an input file we need an ifstream variable
	ifstream inFile;
	ofstream outFile;
	string fname, lname, dept;
	double salary = 0, bonus = 0, miles = 0, time = 0, price = 0, totalSalary = 0, totalPrice = 0, avgSpeed = 0;
	int mugQty = 0;
	//open the file and read
	inFile.open("inData.txt");
	inFile >> fname >> lname >> dept;
	inFile >> salary >> bonus;
	inFile >> miles >> time;
	inFile >> mugQty >> price;
	//manipulate the data
	totalSalary = salary + (salary * (bonus / 100));
	avgSpeed = miles / time;
	totalPrice = mugQty * price;
	//format and output to user
	cout << fixed << showpoint << setprecision(2);
	cout << fname << " " << lname << " " << dept << endl;
	cout << "Total Salary = $" << totalSalary << endl;
	cout << "Average Speed = " << avgSpeed << " mph" << endl;
	cout << "Total Sales Amount = $" << totalPrice << endl;
	//open output file and output to file
	outFile.open("outData.txt");
	outFile << fixed << showpoint << setprecision(2);
	outFile << fname << " " << lname << " " << dept << endl;
	outFile << "Total Salary = $" << totalSalary << endl;
	outFile << "Average Speed = " << avgSpeed << " mph" << endl;
	outFile << "Total Sales Amount = $" << totalPrice << endl;
	//close the file
	inFile.close();
	outFile.close();

	return 0;
}