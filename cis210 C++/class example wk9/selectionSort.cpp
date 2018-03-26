//This program demos selection sort
//Gayathri Iyer
//12-September-2014
//Sources:None
#include <iostream>
using namespace std;

const int CAP = 10;

//function prototype
void selectionSort(int list[]);

int main()
{
	int list[CAP] = {6, 45, 76, 1, 4, 129, 9, 19, 12, 2123};
	selectionSort(list);

	//print the list
	for(int i = 0; i < CAP; i++)
		cout << list[i] << endl;

	return 0;
}

void selectionSort(int list[])
{
	int smallIndex = 0, loc = 0, temp = 0;
	for(int i = 0; i < CAP - 1; i++)
	{
		//find the smallest
		smallIndex = i;
		for(loc = i+1; loc < CAP; loc++)
		{
			if(list[loc] < list[smallIndex])
				smallIndex = loc;
		}
		//swap the 2 numbers (i and smallIndex)
		temp = list[smallIndex];
		list[smallIndex] = list[i];
		list[i] = temp;
	}

}
