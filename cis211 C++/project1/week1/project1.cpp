//
//  main.cpp
//  week1
//
//  Created by Bin Li on 6/21/16.
//  Copyright © 2016 Bin Li. All rights reserved.
//

/*Have you ever been low on cash and couldn’t go beyond a certain dollar limit when shopping?
 You sort of need a calculator in your head. It would be cool if a device was actually part of the
 cart and as you add an item into the cart it would increment your total counter. To solve this, we
 are going to write a program that keeps a tally of the amount that we have spent so far as we visit
 a store.
 What Your Program Should Do:
 1. Allow the shopper (user) to enter in the product name and the cost. This should be echoed
 and confirmed. Make sure to check for bad data.
 2. The user should be allowed to continue this until they want to check out.
 3. Your program needs to keep a running total.
 4. Upon checkout, the grand total should be displayed.
 5. Display money using proper formatting. You will need to have the following before
 displaying dollars and cents:
 cout.setf(ios::fixed, ios::floatfield);
 cout.setf(ios::showpoint);
 cout.precision(2);*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//the one function i'm using
double item_info(double, char[100]);

int main()
{
    
    //Declare varibles.
    char itemName[100];
    double itemPrice;
    char option;
    double total;
    double runningTot;
    total = 0.00;
    
    // Setting output decimal point.
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    runningTot = item_info(itemPrice, &itemName[100]);
    total = total + runningTot;
    
    //Ask if user wants to continue y or n
    cout << "Would you like to add more items (Y / N)";
    cin >> option;
    cin.ignore(100, '\n');
    
    //runs the function again when option is y
    while (option == 'Y' || option == 'y')
    {
        runningTot = item_info(itemPrice, &itemName[100]);
        cout << "Would you like to add more items (Y / N)";
        cin >> option;
        cin.ignore(100, '\n');
        total = total + runningTot;
        //breaks out of loop if option is n
        if (option == 'n' || option == 'N')
            break;
    }
    
    cout << "Grand Total: $" << total << endl;
    cout << 46 + 15.0 / 2 - 1;
    
    return 0;
    
}


double item_info(double itemPrice, char itemName[100])
{
    //Ask for user input.
    cout << "Enter the item name: ";
    cin.get(itemName, '\n');
    
    cin.ignore(100, '\n');
    
    //Ask for the price of the item.
    cout << "Enter the price: ";
    cin >> itemPrice;
    
    //Check if valid data
    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input! Enter the item's price again: ";
        cin >> itemPrice;
    }
    
    //Ignore enter and space after input.
    cin.ignore(100, '\n');
    
    //Print the user input.
    cout << "Item information: " << itemName <<": $" << itemPrice << endl;
    return itemPrice;
}