// This is an example of a simple sentinel controlled loop
// Author: Gayathri Iyer
// Date: 06/27/2014
// Sources: None

#include <iostream>
#include <string>

using namespace std;

const string PASSWORD = "secret";

int main ()
{
    string line;
    cout << "Please enter the secret password: ";
    getline(cin, line);
	while (line != PASSWORD)
	{
        cout << "Incorrect. Please try again: "; 
		getline(cin, line);
    }
    cout << "Correct!" << endl;
    
    char reply;
    cout << "Enter q to quit: ";
    cin >> reply;
    return 0;   
}
