//This program demos 2 dim arrays using students and quiz scores
//Gayathri Iyer
//12-September-2014
//Source: None

#include <iostream>
using namespace std;

//constants
const int STDS = 3;
const int QZS = 2;

int main()
{
	int scores[STDS][QZS];
	int total = 0, average = 0;

	for(int i = 0; i < STDS; i++)
	{
		cout << "Enter scores for student #" << i << ":" << endl;
		for(int j = 0; j < QZS; j++)
			cin >> scores[i][j];
	}

	//print the scores
	for(int i = 0; i < STDS; i++)
	{
		cout << "Scores for student #" << i << ":" << endl;
		for(int j = 0; j < QZS; j++)
			cout << scores[i][j] << " ";
		cout << endl;
	}
	//average for every student
	for(int i = 0; i < STDS; i++)
	{
		total = 0;
		for(int j = 0; j < QZS; j++)
		{
			total += scores[i][j];
		}
		average = total / QZS;
		cout << "Average for student " << i << "  = " << average << endl;
	}
	return 0;
}