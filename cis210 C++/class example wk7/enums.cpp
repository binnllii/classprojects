// Demo of "enum" types
// Gayathri Iyer
// Sources: None
// Date: 05-September-2014

#include <iostream>
#include <string>

using namespace std;

// Declare Size and Color as new Data Types
enum Size  { SMALL, MEDIUM, LARGE };
enum Color { RED, GREEN, BLUE };

// These are "utility" functions
string colorToString(Color color);
string sizeToString(Size size);

int main()
{
	// Declare two variables of type Color
	Color myColor, yourColor;
	// Declare two variables of type Size
	Size  mySize, yourSize;

	myColor = GREEN;
	mySize = MEDIUM;

	yourColor = myColor;
	yourSize = static_cast <Size> (mySize + 1);

	cout << "My color is " << colorToString(myColor) << endl;
	cout << "My Size is " << sizeToString(mySize) << endl;
	cout << "Your color is " << colorToString(yourColor) << endl;
	cout << "Your Size is " << sizeToString(yourSize) << endl;

	char reply;
	cout << "Enter q to quit: " << endl;
	cin >> reply;
	return 0;
}


string colorToString(Color color)
{
	switch (color) {
	case RED:
		return "red";
	case GREEN:
		return "green";
	case BLUE:
		return "blue";
	default:
		return "unknown";
	}
}

string sizeToString(Size size)
{
	switch (size) {
	case SMALL:
		return "small";
	case MEDIUM:
		return "medium";
	case LARGE:
		return "large";
	default:
		return "unknown";
	}
}

