// This is an example of a more complicated loop structure.
// Author: Gayathri Iyer
// Date: 06/29/2014
// Sources: None

#include <iostream>
#include <string>

using namespace std;

const string password = "secret";

int main ()
{
    string line;
    int failures;        // failures counts the number of failed attempts
    
    failures = 1;        // initialize it to 1
    // Read the user's password and see if it is correct.
    cout << "Please enter the secret password: ";
    getline(cin, line);

    // We must terminate the loop if the password is correct, ...
    // ... the user enters 'q'or the failure count reaches 3
	while (failures < 3 && line != password && line != "q")
	{
        // The user entered the wrong password so increment failures      
        failures++;
        cout << "Incorrect. Please try again (or q to quit): "; 
        getline(cin,line);
    }

    // We must check what caused the loop to terminate
    if (line == password) 
	{
        cout << "Correct!" << endl;         
    } 
	else if (line == "q") 
	{
        cout << "Goodbye!" << endl;      
    } 
	else
	{
        cout << "You exceeded 3 attempts" << endl;
        cout << "Goodbye!" << endl;
    }
    
    char reply;
    cout << "Enter q to quit: ";
    cin >> reply;
    return 0;   
}
