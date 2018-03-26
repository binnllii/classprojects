//This program will make a box of stars, that is 15 wide and 8 high
//Gayathri Iyer
//12-September-2014
//Sources:None

#include <iostream>
using namespace std;

int main()
{
	int x = 25, y = 8;
	for(int i = 0; i < y; i++)
	{
		for(int j = 0; j < x; j++)
			cout << '*';
		cout << endl;
	}
	return 0;
}