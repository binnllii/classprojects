// This is a payroll calculation
// It makes heavy use of various funtions, and has lots of error checking
// ...and validation
// Author: Gayathri Iyer
// Date: 04-September-2014
// Sources: None

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double MIN_WAGE = 7.50;
const double MAX_WAGE = 14.00;
const double MIN_HOURS = 0.0;
const double MAX_HOURS = 50.0;
const double BASE_HOURS = 40.0;
const double OVERTIME_RATE = 1.5;

// These are the funtion prototypes.
// They are like a table of contents of the functions present in the source file.
double readDouble();
bool   rangeCheck(double value, double min, double max); 
double calculatePay(double hours, double rate);
void   abortProgram();

int main()
{
	double wage = 0, hours = 0, grossPay = 0;
	cout << fixed << showpoint << setprecision(2);
	//user input
	cout << "Please enter your hourly wage: $";
	wage = readDouble();
	if (!rangeCheck(wage, MIN_WAGE, MAX_WAGE)) 
	{
		cout << "Wage must be between $" << MIN_WAGE << " and $" << MAX_WAGE << endl;
		abortProgram();
	}
	cout << "Please enter your hours worked: ";
	hours = readDouble();
	if (!rangeCheck(hours, MIN_HOURS, MAX_HOURS)) 
	{
		cout << "Hours must be between " << MIN_HOURS << " and " << MAX_HOURS << endl;
		abortProgram();
	}
	grossPay = calculatePay(hours, wage);
	cout << "Your gross pay is: $" << grossPay << endl;

	char reply;
	cout << "Please enter q to quit: ";
	cin >> reply;

	return 0;
}

// This function returns the number the user inputs in the input stream (cin).
// It should be robust against numeric syntax errors.
double readDouble()
{
	double number = 0;
	cin >> number;
	// Test if the input stream has entered the 'fail' state.
	// This would happen if the input was not a valid number of type double.
	while (cin.fail()) 
	{
		cin.clear();            // Clear the fail flag.
		cin.ignore(1000, '\n');  // Skip the rest of the line with the error.
		cout << "Please enter a valid number." << endl;
		cout << "Please try again: ";
		cin >> number;
	}
	return number;
}

// This function returns 'true' if value is between min and max.
bool rangeCheck(double value, double min, double max)
{
	if (value >= min && value <= max) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

// Inputs: hours = hours worked
//         rate = hourly rate
// Output: gross pay earned
// Calculation:
//         The gross pay is hours worked times hourly rate
//         but overtime is paid for hours in excess of BASE_HOURS
//         at the rate of OVERTIME_RATE
double calculatePay(double hours, double rate)
{
	double basePay;
	double overtimePay;
	if (hours <= BASE_HOURS)
	{
		basePay = hours * rate;
		overtimePay = 0.0;
	}
	else 
	{
		basePay = BASE_HOURS * rate;
		overtimePay = rate * OVERTIME_RATE * (hours - BASE_HOURS);
	}
	return basePay + overtimePay;
}

// This function aborts the program without 'flashing off the screen'.
void abortProgram()
{
	char reply;
	cout << "Please enter q to quit: ";
	cin >> reply;
	exit(1);
}

