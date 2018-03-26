
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


//Object oriented programming

#include "CoffeeShop.h" //uses the header file CoffeeShop.h

//starts the function
int main()
{
    //call coffeeshop function
    
    CoffeeShop Shop;
    
    Shop.toUse();
    
    return 0;
}










//#include <iostream>
//using namespace std;
//
////const int small = 9, medium = 12, large = 15;
//const double smallCost = 1.75, mediumCost = 1.90, largeCost = 2.00;
//
//int useProgram();
//
//void sellCoffee(int nscups, int nmcups, int nlcups, double tscups,
//                double tmcups, double tlcups,double ttlcost);
//
//void initial(int nscups, int nmcups, int nlcups, double tscups,
//             double tmcups, double tlcups, double ttlcost);
////void numCups
////void amountSold
////void moneyMade
//
//int main()
//{
//    int nscups, nmcups, nlcups;
//    double tscups, tmcups, tlcups, ttlcost;
//    switch(useProgram())
//    {
//        case 1:;
//            cout << "You chose to buy a coffee." << endl;
//            initial(nscups, nmcups, nlcups, tscups, tmcups, tlcups, ttlcost);
//            sellCoffee(nscups, nmcups, nlcups, tscups, tmcups, tlcups, ttlcost);
//            cout << ttlcost;
//            
//            
//            break;
//        case 2:;
//            cout << "You chose to find out how many cups you have sold" << endl;
//            break;
//        case 3:;
//            cout << "You chose to see how many ounces you have sold" << endl;
//            break;
//        case 4:;
//            cout << "You chose how much money you have made" << endl;
//            break;
//            
//            
//    }
//    
//}
//
//void initial(int nscups, int nmcups, int nlcups, double tscups,
//             double tmcups, double tlcups, double ttlcost)
//{
//    nscups = 0;
//    nmcups = 0;
//    nlcups = 0;
//    tscups = 0;
//    tmcups = 0;
//    tlcups = 0;
//    ttlcost = 0;
//}
//
//
//int useProgram()
//{
//    int number;
//    cout << "Enter a 1 if you want to buy coffee." << endl;
//    cout << "Enter a 2 if you want to see how many cups you have sold." << endl;
//    cout << "Enter a 3 if you want to see how many ounces you have sold." << endl;
//    cout << "Enter a 4 if you want to see how much money you have made." << endl;
//    cout << "Enter your choice: ";
//    cin >> number;
//    return number;
//}
//
//void sellCoffee(int nscups, int nmcups, int nlcups, double tscups,
//                double tmcups, double tlcups, double ttlcost)
//{
//    char yesno;
//    char size;
//
//        cout << "Would you like some coffee (y/n): ";
//        cin >> yesno;
//
//while (true)
//{
//    if ((yesno = 'y'))
//    cout << "What size would you like (s, m, or, l): ";
//    cin >> size;
//    if (size == 's')
//    {
//        cout << "How many small cups do you want: ";
//        cin >> nscups;
//        tscups = nscups * smallCost;
//        cout << "The total cost for this purchase is $" << ttlcost + tscups << endl;
//        ttlcost = ttlcost + tscups;
//        cout << "Would you like to purchase another cup (y/n): ";
//        cin >> yesno;
//        
//    }
//    if (size == 'm')
//    {
//        cout << "How many medium cups do you want: ";
//        cin >> nmcups;
//        tmcups = nmcups * mediumCost;
//        cout << "The total cost for this purchase is $" << ttlcost + tmcups << endl;
//        ttlcost = ttlcost + tmcups;
//        cout << "Would you like to purchase another cup (y/n): ";
//        cin >> yesno;
//
//    }
//        
//    if (size == 'l')
//    {
//        cout << "How many large cups do you want: ";
//        cin >> nlcups;
//        tlcups = nlcups * largeCost;
//        cout << "The total cost for this purchase is $" << ttlcost + tlcups << endl;
//        ttlcost = ttlcost + tlcups;
//        cout << "Would you like to purchase another cup (y/n): ";
//        cin >> yesno;
//
//    }
//    else
//        break;
//    
//    
//    
//}
//}

