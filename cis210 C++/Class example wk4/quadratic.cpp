// This is a quadratic equation solver
// Author: Gayathri Iyer
// Date: 06/27/2014
// Sources: None

// The equation ax^2 + bx + c = 0 has the following two solutions:
// x1 = (-b + sqrt (b^2 - 4ac)) / (2a)
// x2 = (-b - sqrt (b^2 - 4ac)) / (2a)


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
	// Variable declarations
	double a = 0, b = 0, c = 0;
	double discriminant = 0;
	double root1 = 0, root2 = 0;
	char reply;

	// Display a welcome banner
	cout << fixed << setprecision(2);
	cout << "Welcome to my Square Root Calculator" << endl;
	
	// Ask the user to enter values for a, b, and c
	cout << "Please enter the value of a: ";
    cin >> a;
	// Error if a is equal to zero.
	if (a == 0.0) {
          cout << "a cannot be zero" << endl;
          // Stop the output 'flashing' off the screen
	      cout << "Press q to quit: ";
	      cin >> reply;
	      exit(1);         // Exit the program with error code '1'
    }
    cout << "You entered the value: " << a << endl;
	cout << "Please enter the value of b: ";
	cin >> b;
	cout << "You entered the value: " << b << endl;
	cout << "Please enter the value of c: ";
	cin >> c;
	cout << "You entered the value: " << c << endl;

	// Calculate the discriminant (b squared - 4ac)
	discriminant = pow(b, 2) - 4*a*c;

	if (discriminant > 0) {
		// In this case the roots are "real"
		// Calculate the first root
		root1 = (-b + sqrt(discriminant))/(2*a);
	
		// Calculate the second root
		root2 = (-b - sqrt(discriminant))/(2*a);
	
		// Display the two square roots
		cout << "The first root is: "  << root1 << endl;
		cout << "The second root is: " << root2 << endl;
	}
	else if (abs(discriminant) <= 0.0000000001) {
        // In this case, both roots are equal
        root1 = (-b) / (2*a);
        // Display the only square root
		cout << "The only root is: "  << root1 << endl;
    } 
	else {
    	// In this case the roots are "imaginary"
		cout << "Your equation has imaginary roots." << endl;      
    }
    
	// Stop the output 'flashing' off the screen
	cout << "Press q to quit: ";
	cin >> reply;
	return 0;
}
