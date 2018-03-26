// This is a demonstration of how to use a function in C++
// Author: Gayathri Iyer
// Date: 03-September-2014
// Sources: None

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double BASE_HOURS = 40.0;
const double OVERTIME_RATE = 1.5;

// This is the function prototype.
// It is necessary because you must declare calculatePay() before you use it in main().
double calculatePay(double hours, double rate);

int main()
{
	double hourlyRate = 0, hoursWorked = 0, grossPay = 0;

	cout << fixed << showpoint << setprecision(2);
	//user input
	cout << "What is your hourly rate: ";
	cin >> hourlyRate;
	cout << "How many hours did you work this week: ";
	cin >> hoursWorked;
	grossPay = calculatePay(hoursWorked, hourlyRate);
	cout << "Your gross pay is $" << grossPay << endl;

	char reply;
	cout << "Enter q to quit: ";
	cin >> reply;
	return 0;
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
	double basePay = 0;
	double overtimePay = 0;
	//If hours <= 40, then base pay is hours times rate
	if (hours <= BASE_HOURS) 
	{
		basePay = hours * rate;
		overtimePay = 0.0;
	}
	//else if hours > 40, then base pay is 40 times rate, and overtime is 1.5 times the rate for the remaining hours.
	else 
	{
		basePay = BASE_HOURS * rate;
		overtimePay = rate * OVERTIME_RATE * (hours - BASE_HOURS);
	}
	return basePay + overtimePay;
}