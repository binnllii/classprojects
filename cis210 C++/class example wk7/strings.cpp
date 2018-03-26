//This program demos string find.  Searches for a word in the title of the book.
//Gayathri Iyer
//05-September-2014
//Sources:none

#include <iostream>
#include <string>

using namespace std;

//function prototype
void strtoUpper(string &title);

int main()
{
	string title, searchStr;
	title = "C++ Programming:From Problem Analysis to Program Design";
	cout << "Enter your search string:";
	getline(cin, searchStr);
	strtoUpper(title);
	strtoUpper(searchStr);

	//search for the string
	if(title.find(searchStr) < title.length())
		cout << title << endl;
	else
		cout << "Title not found!!" << endl;

	return 0;
}

//function to convert string to upper case
void strtoUpper(string &title)
{
	int i = 0;
	for(i = 0; i < title.length(); i++)
	{
		title[i] = toupper(title[i]);
	}
}

