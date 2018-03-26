// This is a demo of multi-way alternation using if... else if... else...
// Author: Gayathri Iyer
// Date: 06/27/2014
// Sources: None

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
    char reply;
    double maximumScore, yourScore;
    double percentage;
    cout << fixed << showpoint << setprecision(2);
    cout << "Welcome to my Grade Calculator" << endl;
    cout << "What is the maximum possible score: ";
    cin >> maximumScore;
    // Error if zero. Cannot divide by zero later.
	if (maximumScore == 0.0)
	{
		cout << "Error: Maximium cannot be zero." << endl;
		cout << "Enter q to quit: ";
		cin >> reply;
		exit(1);
	}
    
    cout << "What is your score: ";
    cin >> yourScore;
    percentage = (yourScore / maximumScore) * 100;
    cout << "Your percentage correct is: " << percentage << "%" << endl;
    if (percentage >= 90)
	{
       cout << "You got an A" << endl;
    }
	else if (percentage >= 80)
	{
       cout << "You got a B" << endl;  
    } 
	else if (percentage >= 70) {
       cout << "You got a C" << endl;  
    } 
	else 
	{
       cout << "You Failed" << endl;   
    }
    cout << "Enter q to quit: ";
    cin >> reply;
    return 0;   
}
