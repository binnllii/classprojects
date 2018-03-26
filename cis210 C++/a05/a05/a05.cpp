/*Jason typically uses the Internet to buy various items. If the total cost of the items
 ordered, at one time, is $200 or more, then the shipping and handling is free; otherwise
 the shipping and handling is $10 per item. Write a menu driven program that prompts
 Jason to enter the item name, quantity, and price of the item. Use a loop to display the
 menu until Jason enters ‘q’ to quit. When he quits, display the total cost of the items, the
 shipping cost for all the items, and then the total billing amount including the cost of the
 items and the shipping cost.
 
 1. You must use loops, since this is an exercise in loops.
 2. No global variables. All variables must be inside main().
 3. You must be able to read text with spaces, so use getline() for the string data type.
 4. The menu must display continuously after every turn, until the user enters ‘q’ to
 quit.
 5. There is no need to store the past items. All you need to do is to maintain a
 running total, to calculate the shipping cost and then output the cost.*/


//case 1: items add up to 200
//case 2: items dont add up to 200
//display total cost of items
//display shipping cost of items
//total billing amount/ shipping plus items
//use loops

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//functions
double calcCost(int quan, double cost);
double shipCost(int quan, double cost);

int main()
{
    //declare variables
    int quanItem;
    string itemName = " ";
    double costItem = 0, totCost = 0, totShip = 0, overallCost = 0;
    //get user input using while loop
    while (itemName != "q")
    {
        cout << fixed << showpoint << setprecision(2);
        cout << "Enter the item name or q to quit: ";
        //getline used for strings
        getline(cin, itemName);
        //if equals q, quit the print out the results
        if (itemName == "q")
            break;
        cout << "Enter the Quantity of the item you want: ";
        cin >> quanItem;
        cout << "How much does your item cost? ";
        cin >> costItem;
        //+= keeps the running total
        totCost += calcCost(quanItem, costItem);
        totShip += shipCost(quanItem, costItem);
        //after the data is manupliated using the totCost and totShip functions, you need to set what to output using this if else statements
        if (totCost >= 200)
            totShip = 0;
        //calculate the total cost which is shipping + cost if items
        overallCost = totCost + totShip;
        //This is NOT apart of the conditions that it needed to meet but, this condition applies if the cost of the items are under 200 but when you add in shipping it goes over 200, since at 200 dollars we offer free shipping, we will make it 200 dollars.
        
        //if ((totCost + totShip) > 200 && totShip != 0)
        //   overallCost = 200;
        //cin.ignore will ignore the space/ enter that comes after you input
        cin.ignore();
    }
    //output the data.
    cout << "The total cost of the items W/O shipping is $" << totCost << endl;
    cout << "The total shipping cost is $" << totShip << endl;
    cout << "The total cost of the items plus shipping is $" << overallCost << endl;
}

//functions to calculate the total cost and total shipping costs
double calcCost(int quan, double cost)
{
    double totalCost;
    totalCost = quan * cost;
    return totalCost;
}

double shipCost(int quan, double cost)
{
    //if else statement, if overall cost less than 200, then shipping per item is 10 dollars
    //else it is free, or 0 dollars

    double totalShip = 0;
    if(quan * cost <= 200)
    {
        totalShip = quan * 10;
    }
    else
    {
        totalShip = 0;
    }
    return totalShip;
}




    






//Not menu driven
//int main()
//{
//    //set variables
//    int quanItem;
//    string itemName = " ";
//    double costItem, totCost, allCost = 0, allItems = 0;
//    //while loop
//    while (itemName != "q")
//    {
//        //get user input
//        cout << "Enter the item name or q to quit: ";
//        getline(cin, itemName);
//            if (itemName == "q")
//                break;
//        cout << "Enter the Quantity of the item you want: ";
//        cin >> quanItem;
//        cout << "How much does your item cost? ";
//        cin >> costItem;
//        cin.ignore();
//        totCost = quanItem * costItem;
//        allItems = allItems + quanItem;
//        allCost = allCost + totCost;
//        //cout answers
//        cout << fixed << showpoint << setprecision(2);
//        cout << allCost << endl;
//        if (allCost < 200)
//        {
//            cout << "The total price of your items is " << (allItems * 10) + allCost << " dollars" << endl;
//        }
//        else
//        {
//            cout << "The total price of your items is " << allCost << " dollars" << endl;
//        }
//
//
//    }
//    //cout the final costs
//    cout << "The total price of your items is " << allCost << " dollars." << endl;
//    if (allCost < 200)
//    {
//        cout << "The total shipping costs of your items are " << (allItems * 10) << " dollars." << endl;
//        cout << "The total price of your items plus shipping are " << (allItems * 10) + allCost << " dollars." << endl;
//    }
//    else
//    {
//        cout << "Your shipping is FREE." << endl;
//        cout << "The total price of your items plus shipping are " << allCost << " dollars." << endl;
//    }
//
//
//}
//
////Menu driven
//
///*Jason typically uses the Internet to buy various items. If the total cost of the items
// ordered, at one time, is $200 or more, then the shipping and handling is free; otherwise
// the shipping and handling is $10 per item. Write a menu driven program that prompts
// Jason to enter the item name, quantity, and price of the item. Use a loop to display the
// menu until Jason enters ‘q’ to quit. When he quits, display the total cost of the items, the
// shipping cost for all the items, and then the total billing amount including the cost of the
// items and the shipping cost.
//
// 1. You must use loops, since this is an exercise in loops.
// 2. No global variables. All variables must be inside main().
// 3. You must be able to read text with spaces, so use getline() for the string data type.
// 4. The menu must display continuously after every turn, until the user enters ‘q’ to
// quit.
// 5. There is no need to store the past items. All you need to do is to maintain a
// running total, to calculate the shipping cost and then output the cost.*/
//
//double calcCost(int quan, double cost);
//double shipCost(int quan, double cost, double calcCost);
//double totCost(int quan, double cost);
//
//
//int main()
//{
//    //Declare variables
//    int quanItem;
//    string itemName = " ";
//    double costItem = 0, totCost = 0, totShip = 0, superCost = 0.0, superShip = 0, overallCost = 0;
//    //get user input with while loop
//    while (itemName != "q")
//    {
//        cout << fixed << showpoint << setprecision(2);
//        cout << "Enter the item name or q to quit: ";
//        getline(cin, itemName);
//        //when itemName == r break and return the results
//            if (itemName == "q")
//                break;
//        cout << "Enter the Quantity of the item you want: ";
//        cin >> quanItem;
//        cout << "How much does your item cost? ";
//        cin >> costItem;
//        //gather information from the functions that is created
//        totCost = calcCost(quanItem, costItem);
//        //i use these superCost and superShip to keep track of the running total of the shipping cost and total cost
//        superCost = superCost + totCost;
//        totShip = shipCost(quanItem, costItem, superCost);
//        superShip = superShip + totShip;
//        if (superCost > 200)
//            superShip = 0;
//        //This condition applies if the cost of the items are under 200 but when you add in shipping it goes over 200, since at 200 dollars we offer free shipping, we will make it 200 dollars.
//        //overallCost will keep track of the overall cost before it loops again.
//        overallCost = superCost + superShip;
//        if (overallCost > 200 && superShip != 0)
//            overallCost = 200;
//
////        cout << "The total cost of the items W/O shipping is $" << superCost << endl;
////        cout << "The total shipping cost is $" << superShip << endl;
////        cout << "The total cost of the items plus shipping is $" << overallCost << endl;
//        cin.ignore();
//    }
//    cout << "The total cost of the items W/O shipping is $" << superCost << endl;
//    cout << "The total shipping cost is $" << superShip << endl;
//    cout << "The total cost of the items plus shipping is $" << overallCost << endl;
//
//
//}
////the 2 functions i use, which generate the shipping cost and total cost of items
//
//double calcCost(int quan, double cost)
//{
//    double totalCost;
//    totalCost = quan * cost;
//    return totalCost;
//}
//
//double shipCost(int quan, double cost, double overall)
//{
//    //if else statement, if overall cost less than 200, then shipping per item is 10 dollars
//    //else it is free, or 0 dollars
//
//    double totalShip = 0, sShip = 0;
//    if(overall < 200)
//    {
//        totalShip = quan * 10;
//        sShip = sShip + totalShip;
//    }
//    else
//    {
//        sShip = 0;
//    }
//    return sShip;
//}
































//NEVER GOING TO USE















//int main()
//{
//    double itemPrice = 0, totalPrice = 0;
//    char qui = ' ';
//    while (itemPrice != 'q')
//    {
//        cout << "Input the price of your item: ";
//        cin >> itemPrice;
//        qui = itemPrice;
//        totalPrice = totalPrice + itemPrice;
//        cout << totalPrice << endl;
//    
//    }
//    
//}


