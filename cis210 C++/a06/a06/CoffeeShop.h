


//sources: http://www.cplusplus.com/forum/beginner/126793/
/*
 Jason opened a coffee shop at the beach and sells coffee in three sizes: small
 (9oz), medium (12oz), and large (15oz). The cost of one small cup is $1.75, one
 medium cup is $1.90, and one large cup is $2.00. Write a menu driven program
 that will make the coffee shop operational. Your program should allow the user
 to do the following:
 a) Buy coffee in any size and in any number of cups.
 b) At any time show the total number of cups of each size sold.
 c) At any time show the total amount (in ounces) of coffee sold.
 d) At any time show the total money made.
 Your program should consist of at least the following functions: a function to
 show the user how to use the program, a function to sell coffee, a function to
 show the number of cups of each size sold, a function to show the total amount of
 coffee sold, and a function to show the total money made. Your program should
 not use any global variables, arrays or vectors. Special values such as coffee cup
 sizes, and cost of a coffee cup must be declared as named constants.
 
 sells coffee at 3 sizes
 a) Buy coffee in any size and in any number of cups.
 b) At any time show the total number of cups of each size sold.
 c) At any time show the total amount (in ounces) of coffee sold.
 d) At any time show the total money made.
 
 a function to show the user how to use the program
 a function to sell coffee
 a function to show the number of cups of each size sold
 a function to show the total amount of coffee sold
 a function to show the total money made
 
 */



#include <iostream>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string>

//Stores all the classes and variables
class CoffeeShop
{
//public can be used anywhere
public:
    //Function declarations
    void toUse();
    void sellCoffee(int type, int amount);
    void cupsSold();
    void amountSold();
    void moneyMade();
    std::pair<int, int> parseString(const std::string &Amount);

 //private can only be used in main
private:
    //Variables and constants 
    double profit;
    const double sPrice = 1.75, mPrice = 1.90, lPrice = 2.00; //Prices of each size
    const int small = 9, medium = 12, large = 15; // ounces of each size
    int tsSold = 0, tmSold = 0, tlSold = 0, sOunce = 0, mOunce = 0, lOunce = 0; // keeps the total of each size/ounce
    
};