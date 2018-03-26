//
//  main.cpp
//  EXC
//
//  Created by Bin Li on 6/3/16.
//  Copyright © 2016 Bin Li. All rights reserved.
//

#include <iostream>

using namespace std;
int main()
{
    //variables
    double number1, number2;
    char operation;
    cout << "Enter the operation:\nNumber then (+,-,*,/) then number: ";
    cin >> number1 >> operation >> number2; // user input
    
    //depends on what you enter for operation
    switch(operation)
    {
            //couts the approprate solution
        case '+':
            cout << number1 + number2 << endl;
            break;
        case '-':
            cout << number1 - number2 << endl;
            break;
        case '*':
            cout << number1 * number2 << endl;
            break;
        case '/':
            if (number2 == 0)
            {
                cout << "You cannot divide by 0." << endl;
                break;
            }
            cout << (number1 / number2) << endl;
            break;
            
    }
}