/* This program demonstrates how to use external file to store data.

   Written by: Li Liang
   Date: 09/20/2009

   Sources: None
*/

#include <iostream>                 
#include <string>    
#include <cctype>
#include <iomanip>
#include <fstream>

using namespace std;     

//named constants
const int MAX_CHAR = 101;
const int NAME_COL_WIDTH = 30;
const int EMAIL_COL_WIDTH = 40;
const int ADDRESS_BOOK_CAPACITY = 100;

//define a new data type AddressEntry
struct AddressEntry
{
	char	name[MAX_CHAR];
	char	email[MAX_CHAR];
}; //don't forget this ';'

//user-interface related functions
void displayMenu();
char readInCommand();
void processCommand(char command, AddressEntry list[], int& listSize);
void readInEntry(AddressEntry& anEntry);
void readInName(char name[]);

//database related functions
void displayAll(const AddressEntry list[], int listSize);
void addEntry(const AddressEntry& anEntry, AddressEntry list[], int& listSize);
bool searchEntry(const char name[], AddressEntry& match, const AddressEntry list[], int listSize);

//use external file
void loadAddressBook(const char fileName[], AddressEntry list[], int& listSize);
void saveAddressBook(const char fileName[], const AddressEntry list[], int listSize);

//standard input tools
void readString (const char prompt[], char inputStr[], int maxChar);

int main ()
{
	char			command;
	AddressEntry	list[ADDRESS_BOOK_CAPACITY];
	int				listSize = 0;
	char			fileName[] = "addressBook.txt";
	
	loadAddressBook(fileName, list, listSize);	

	displayMenu();
	command = readInCommand();
	while (command != 'q')
	{
		processCommand(command, list, listSize);
		displayMenu();
		command = readInCommand();
	}

	saveAddressBook(fileName, list, listSize);	
    
    return 0;
}

/* This function reads a c-string from the standard input.
   in: prompt
       maxChar: at most maxChar-1 characters can be stored. The rest of the input will be discarded.
   out: inputStr
   return: none
*/
void readString (const char prompt[], char inputStr[], int maxChar)
{
	cout << endl << prompt;

	//read until it either reaches the maxChar limit or encounters a '\n'
	cin.get(inputStr, maxChar, '\n');
	while(!cin)
	{
		cin.clear ();
		cin.ignore (100, '\n');
		cout << endl << prompt;
		cin.get(inputStr, maxChar, '\n');
	}

	//throw away the '\n'
	cin.ignore (100, '\n');
}

/* This function displays the main menu. */
void displayMenu()
{
	cout << endl << "Welcome to Easy Addressbook!" << endl << endl;
	cout << "\ta: add an entry" << endl
		<< "\tl: list all the entries" << endl
		<< "\ts: search address by name" << endl
		<< "\tq: exit this program" << endl << endl;
}

/* This function reads in user's command.
   return: the command in lower case
*/
char readInCommand()
{
	char	cmd;

	cout << endl << "Please enter the command (a,l,s or q): ";
	cin >> cmd;
	cin.ignore(100, '\n');

	return tolower(cmd);
}

/* This function processes the command passed in.
   in: command
   in/out: list and listSize
*/
void processCommand(char command, AddressEntry list[], int& listSize)
{
	AddressEntry	entry;
	char			name[MAX_CHAR];

	switch (command)
	{
	case 'a': readInEntry(entry);
		      addEntry(entry, list, listSize);
			break;

	case 'l': displayAll(list, listSize);
			break;

	case 's': readInName(name);
			  if(searchEntry(name, entry, list, listSize))
				  cout << endl << "The email address for " << name << ": " << entry.email << endl;
			  else
				  cout << endl << "The email address for " << name << " doesn't exist." << endl;
			break;

	default: cout << endl << "Illegal Command!" << endl;
			break;
	}
}
	
/* This function reads in an address entry.
   out: anEntry
*/
void readInEntry(AddressEntry& anEntry)
{
	char	name[MAX_CHAR];
	char	email[MAX_CHAR];

	//read in name and email
	readString("Please enter the name: ", name, MAX_CHAR);
	readString("Please enter the email: ", email, MAX_CHAR);

	//populate the passed in object
	strcpy(anEntry.name, name);
	strcpy(anEntry.email, email);
}

/* This function reads in name.
   out: name
*/
void readInName(char name[])
{
	readString("Please enter the name you want to search: ", name, MAX_CHAR);
}

/* This function displays all the entries in the address book.
   in: list, listSize
*/
void displayAll(const AddressEntry list[], int listSize)
{
	int index;
	cout << setw(NAME_COL_WIDTH) << "Name" << setw(EMAIL_COL_WIDTH) << "Email" << endl;
	for(index=0; index<listSize; index++)
	{
		cout << setw(NAME_COL_WIDTH) << list[index].name << setw(EMAIL_COL_WIDTH) << list[index].email << endl;
	}
}

/* This function adds one entry to the end of the address book.
   in: anEntry
   in/out: list, listSize
*/
void addEntry(const AddressEntry& anEntry, AddressEntry list[], int& listSize)
{
	strcpy(list[listSize].email, anEntry.email);
	strcpy(list[listSize].name, anEntry.name);
	listSize++;
}

/* This function searches an entry by name.
   in: name, list, listSize
   out: match
   return: true if a match is found and match contains the entry
           false if a match is not found and match contains garbage
*/
bool searchEntry(const char name[], AddressEntry& match, const AddressEntry list[], int listSize)
{
	int index;
	for(index=0; index<listSize; index++)
	{
		if(strcmp(name, list[index].name) == 0)
		{
			strcpy(match.email, list[index].email);
			strcpy(match.name, list[index].name);
			break;
		}
	}
	if (index == listSize)
		return false;
	else
		return true;
}

/* This function loads the address entries from the external data file.
   in: fileName
   in/out: list, listSize
*/
void loadAddressBook(const char fileName[], AddressEntry list[], int& listSize)
{
	ifstream		in;
	char			name[MAX_CHAR];
	char			email[MAX_CHAR];
	AddressEntry	anEntry;

	in.open (fileName);
	if(!in)
	{
		in.clear();
		cerr << endl << "Fail to open " << fileName << " for input!" << endl << endl;
		exit(1);
	}

	in.get(name, MAX_CHAR, ';');
	while (!in.eof())
	{
		in.get();							//remove field seperator ';'			
		in.get(email, MAX_CHAR, '\n');
		in.ignore(100, '\n');				//remove record seperator '\n'

		strcpy(anEntry.email, email);
		strcpy(anEntry.name, name);

		addEntry(anEntry, list, listSize);

		in.get(name, MAX_CHAR, ';');		//start the next record
	}
	in.close();
}

/* This function saves the array to the external file.
   in: fileName, list, size
*/
void saveAddressBook(const char fileName[], const AddressEntry list[], int listSize)
{
	ofstream		out;
	int				index;

	out.open (fileName);
	if(!out)
	{
		out.clear();
		cerr << endl << "Fail to open " << fileName << " for output!" << endl << endl;
		exit(1);
	}

	for(index=0; index<listSize; index++)
	{
		out << list[index].name << ';' << list[index].email << endl;
	}

	out.close();
}