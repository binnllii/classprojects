//This program demos namespaces
//Gayathri Iyer
//05-September-2014
//Sources: None
#include <iostream>
using namespace std;

namespace globalType
{
	const double PI = 3.14159;
	int x = 10;
	double z = 12.5;
	void printSomething();
}

namespace assignment
{


}
	
int main()
{
	int x = 0;
	cout << "Enter a number:";
	cin >> globalType::x;
	cout << "You entered " << globalType::x << endl;
	cout << "Enter another number:";
	cin >> x;
	cout << "You entered " << x << endl;
	globalType::printSomething();

	return 0;
}

void globalType::printSomething()
{
	cout << "Print Something!" << endl;
}