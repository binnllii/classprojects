// This is a demo of some simple 'while' loops and for loops in C++
// Author: Gayathri Iyer
// Date: 06/29/2014
// Sources: None

#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int n = 0;
    int i = 0;
    int total = 0;
	char reply;

    cout << "This program will add the first n integers." << endl;
	do
	{
		cout << "Please enter a value for n: ";
		cin >> n;
		//check for input failure
		while (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input!! Please try again!!";
			cin >> n;
		}
		// This loop iterates over and over until the user enters a number > 0
		while (n <= 0)
		{
			cout << "Error: n must be greater than zero." << endl;
			cout << "Please try again: ";
			cin >> n;
		}
		total = 0;           // You must initialize total to zero. It is not automatic.
		i = 1;               // i is the loop control variable. It is initialized to 1.
		// This is a for loop. i = 1, 2, 3,... until it reaches n.
		for (i = 1; i <= n; i++)
			total += i;      // same as total = total + i;

		cout << "The sum of the first " << n << " integers is " << total << "." << endl;
		//ask the user if they want to repeat
		cout << "Do you want to repeat? (y/n)";
		cin >> reply;
	} while (reply == 'y');
   
    cout << "Please enter q to quit: ";
    cin >> reply;
    return 0;   
}
