//prompt user to enter a number between 0-35
//
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    //set variables
    int num;
    //ask for user input
    cout << "Please enter a number between 0 and 35: ";
    cin >> num;
    //set conditions then output the appropriate answer
    if (num >= 0 && num <= 9 )
        cout << num << endl;
    if (num >= 10 && num <= 35)
        cout << static_cast<char>(65 + (num - 10)) << endl;
    if (num < 0 || num > 35)
        cout << "Your number is not between 0 and 35" << endl;
    
    return 0;
        
}

int main()
{
    //variables
    float s1, s2, s3;
    //prompt users to enter the sides
    cout << "Enter the sides you want seperated by spaces:";
    cin >> s1 >> s2 >> s3;
    //cout << sqrt(s3)
    //conditions it must meet before it is a right triangle.
    if ((pow(s1, 2) + pow(s2, 2)) == pow(s3, 2) || (pow(s1, 2) + pow(s3, 2)) == pow(s2, 2) || (pow(s2, 2) + pow(s3, 2)) == pow(s1, 2))
        //output if it is or not.
        cout << "It is a right triangle" << endl;
    else
        cout << "It is not a right triangle" << endl;
    
    return 0;
    
    
}

