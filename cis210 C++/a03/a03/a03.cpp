/*
 Welcome to Gayathri’s Fare Calculator
 Are you driving a vehicle onto the ferry? (y/n): y
 Is the driver a senior citizen (65 or over) or disabled? (y/n): y
 How many passengers in your vehicle? (excluding the driver)
 Adults (age 19 – 64): 1
 Senior Citizens (65 or older), or Disabled Persons: 1
 Youth (5 -18 years old): 2
 Is your vehicle over 7 feet, 6 inches in height? (y/n): y
 How long is your vehicle in feet? 17
 How many people in your group are traveling with a bicycle? 0
 Your total fare is $115.55 Gayathri’s Fare Calculator
 
 Welcome to Gayathri’s Fare Calculator
 Are you driving a vehicle onto the ferry? (y/n): y
 Is the driver a senior citizen (65 or over) or disabled? (y/n): n
 How many passengers in your vehicle? (excluding the driver)
 Adults (age 19 – 64): 1
 Senior Citizens (65 or older), or Disabled Persons: 1
 Youth (5 -18 years old): 2
 Is your vehicle over 7 feet, 6 inches in height? (y/n): y
 How long is your vehicle in feet? 27
 How many people in your group are traveling with a bicycle? 0
 Your total fare is $171.25
 Thank you for using Gayathri’s Fare Calculator
 
 Example #3
 Welcome to Gayathri’s Fare Calculator
 Are you driving a vehicle onto the ferry? (y/n): n
 How many adults (age 19 – 64): in your group? 2
 How many senior citizens (65 or older), or disabled persons in your
 group? 2
 How many youth (5-18) in your group? 3
 How many people in your group are traveling with a bicycle? 2
 Your total fare is $62.15
 Thank you for using Gayathri’s Fare Calculator
 */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
    //set variables
    char inferry, issenior = 0, over76 = 0;
    int adults, seniors, youths, bikes, vehicleleng;
    double adultmon, seniormon, youthmon, bikemon, vehmon, total;
    // ask all the questions and get inputs from the users
    cout << "Welcome to the Binny Fare Calculator!" << endl;
    cout << "Are your driving the vehicle into the ferry? (y/n): ";
    cin >> inferry;
    if (inferry == 'y')
    {
        cout << "Is the driver a senior citizen (65 or over) or disabled? (y/n): ";
        cin >> issenior;
    }
    cout << "How many passengers in your vehicle? (excluding the driver)" << endl;
    cout << "Adults (age 19 - 64): ";
    cin >> adults;
    cout << "Senior Citizens (65 or older), or Disabled Persons: ";
    cin >> seniors;
    cout << "Youth (5 -18 years old): ";
    cin >> youths;
    if (inferry == 'y')
    {
        cout << "Is your vehicle over 7 feet, 6 inches in height? (y/n): ";
        cin >> over76;
        cout << "How long is your vehicle in feet? ";
        cin >> vehicleleng;
    }
    cout << "How many people in your group are traveling with a bicycle? ";
    cin >> bikes;
    //use the inputs to calculate the amount of money it costs
    adultmon = adults * 12.95;
    seniormon = seniors * 6.45;
    youthmon = youths * 6.45;
    bikemon = bikes * 2;
    //all the possibilities of vehicle costs depending on length, and is senior or not
    if (vehicleleng < 22 )
    {
        if (vehicleleng < 14 && over76 == 'n' && issenior == 'n')
            vehmon = 36.05;
        if (vehicleleng < 14 && over76 == 'y' && issenior == 'n')
            vehmon = 71.85;
        if (vehicleleng < 14 && over76 == 'n' && issenior == 'y')
            vehmon = 29.55;
        if (vehicleleng < 14 && over76 == 'y' && issenior == 'y')
            vehmon = 65.35;
    //for leng over 14
        if (vehicleleng > 14 && over76 == 'n' && issenior == 'n')
            vehmon = 45.00;
        if (vehicleleng > 14 && over76 == 'y' && issenior == 'n')
            vehmon = 89.75;
        if (vehicleleng > 14 && over76 == 'n' && issenior == 'y')
            vehmon = 38.50;
        if (vehicleleng > 14 && over76 == 'y' && issenior == 'y')
            vehmon = 83.25;
    }
    //for all length over 22
    else if (vehicleleng < 30)
    {
        if (over76 == 'n')
            vehmon = 69.60;
        else
            vehmon = 138.95;
    }
    else if (vehicleleng < 40)
        vehmon = 185.95;
    else if (vehicleleng < 50)
        vehmon = 232.95;
    if (vehicleleng > 50)
        cout << "Your vehicle length cannot go past 50 units.";
    
    //calculate the cost and output the answer.
    total = adultmon + seniormon + youthmon + bikemon + vehmon;
    cout << "Your total fare is $" << total << endl;
    cout << "Thank your for using binnys calculator!" << endl;
    
        
    
    
    return 0;
    
}


