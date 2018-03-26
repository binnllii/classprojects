//This program demos arrays and functions
//It finds the largest element in the array using functions.
//Arrays are passed by default as reference parameters
//Gayathri Iyer
//10-September-2014
//sources:None

#include <iostream>

using namespace std;

//global constants
const int CAP = 10;

//function prototype
int largest(int list[]);

int main()
{
	int list[CAP] = {0}, i = 0, max = 0;
	
	//read from user into list
	cout << "Enter 10 whole numbers:";

	for(i = 0; i < CAP; i++)
		cin >> list[i];
	//prints the address of the array elements
	for(i = 0; i < CAP; i++)
		cout << "List = " << list + i << endl;

	//output to user forwards
	cout << "You entered:\n";
	for(i = 0; i < CAP; i++)
		cout << list[i] << " ";
	cout << endl;
	//find the largest by calling the function
	max = largest(list);
	cout << "Largest = " << max << endl;

	return 0;
}


//function to find the largest in a list
int largest(int list[])
{
	//find the largest
	int max = list[0], i = 0;
	for(i = 1; i < CAP; i++)
		if(list[i] > max)
			max = list[i];
	return max;
}