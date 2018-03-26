//This program demos basic arrays.  It shows how to find the largest element in an array
//Gayathri Iyer
//10-Septemeber-2014
//Sources:None

#include <iostream>

using namespace std;

//global constants
const int CAP = 10;

int main()
{
	int list[CAP] = {0}, i = 0, max = 0;
	
	//read from user into list
	cout << "Enter 10 whole numbers:";

	for(i = 0; i < CAP; i++)
		cin >> list[i];

	//output to user forwards
	cout << "You entered:\n";
	for(i = 0; i < CAP; i++)
		cout << list[i] << " ";
	cout << endl;

	//find the largest
	max = list[0];
	for(i = 1; i < CAP; i++)
		if(list[i] > max)
			max = list[i];
	cout << "Largest = " << max << endl;

	return 0;
}
