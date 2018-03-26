//Get the radius of a circle from the user and write a program to calculate the area and circumference of the circle.
//Goals for this program - define variables and their data types, use constants, calculate data and output to the user.
//Area = PI*r*r
//Circumference = 2*PI*r
//Use manipulators to format my output

#include <iostream>
#include <iomanip>
using namespace std;

//global constants
const double PI = 3.14159;

int main()
{
	double radius = 0, area = 0, circumference = 0;
	//read from the user
	cout << "Please enter the radius of the circle:";
	cin >> radius;
	//calculate area and circumference
	area = PI * radius *radius;
	circumference = 2 * PI * radius;
	//output to the user
	cout << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(20) << "Area = " << setw(15) << right << area << " sq units" << endl;
	cout << left << setw(20) << "Circumference = " << setw(15) << right << circumference << " units" << endl << endl;

	return 0;

}