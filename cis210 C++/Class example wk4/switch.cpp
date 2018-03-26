// This is a demo of the 'switch' statement in C++
// Author: Gayathri Iyer
// Date: 06/27/2014
// Sources: None

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
    char reply;
    double maximumScore, yourScore;
    double percentage;
    cout << fixed << showpoint << setprecision(2);
    cout << "Welcome to my Grade Calculator" << endl;
    cout << "What is the maximum possible score: ";
    cin >> maximumScore;
    // Error if zero. Cannot divide by zero later.
    if (maximumScore == 0.0) {
       cout << "Error: Maximium cannot be zero." << endl;
       cout << "Enter q to quit: ";
       cin >> reply;
       exit(1); 
    }
    cout << "What is your score: ";
    cin >> yourScore;
    percentage = yourScore / maximumScore * 100;
    cout << "Your percentage correct is: " << percentage << "%" << endl;
    // NOTE: The switch expression MUST be of type int OR char.
    // Nothing else is permissible.
    // In this case we divide the percentage by 10 and convert to int...
    // ... using a static_cast. This truncates any fractional part.
    // So we end up with an integer between 0 and 10.
    switch (static_cast<int>(percentage/10)) {
        case 10:
        case 9:
             cout << "You got an A" << endl;
             break;
        case 8:
             cout << "You got a B" << endl;
             break;
        case 7:
             cout << "You got a C" << endl;
             break;  
        default:
             cout << "You Failed" << endl; 
             break;              
    }
    cout << "Enter q to quit: ";
    cin >> reply;
    return 0;   
}
