// sources: http://www.cplusplus.com/forum/beginner/126793/

#include "CoffeeShop.h" //uses header file CoffeeShop.h

//Displays the menu options and asks for user input.
void CoffeeShop::toUse()
{
    std::string input;
    //will run while input is not quit
    while (input != "quit")
    {
    
        //Menu prices
        std::cout << "Coffee Menu Prices:" << std::endl;
        std::cout << "1: Small Coffee: $1.75" << std::endl;
        std::cout << "2: Medium Coffee: $1.90" << std::endl;
        std::cout << "3: Large Coffee: $2.00" << std::endl << std::endl;
        
        //Ask for user input
        std::cout << "Enter 1, 2, or 3 for the size coffee you would like\nto purchase followed by a comma, then enter the\namount of cups you would like or you can:" << std::endl << std::endl;;
        std::cout << "Enter a '4' to see number of cups sold," << std::endl;
        std::cout << "Enter a '5' to see the ounces sold," << std::endl;
        std::cout << "Enter a '6' to see the profits." << std::endl;
        std::cout << "Enter here: ";
        
        //user input either 1,2,3 followed by quantity wanted, or 4,5 or 6.
        std::getline(std::cin, input);
        std::pair<int, int> parsedString = parseString(input); //calls the parsedString function
        
        
        
        
        switch(parsedString.first) //retrieves first value in the pair
        
        //After user input this function gets ran, the switch statement corresponds to what functions to run depending on that the user inputs.
        {
            case 1:
                sellCoffee(parsedString.first, parsedString.second); // retrieves first and second value in the pair
                break;

            case 2:
                sellCoffee(parsedString.first, parsedString.second); // retrieves first and second value in the pair
                break;

            case 3:
                sellCoffee(parsedString.first, parsedString.second); // retrieves first and second value in the pair
                break;
            case 4:
                cupsSold(); // calls function
                break;
            case 5:
                amountSold(); // calls function
                break;
            case 6:
                moneyMade(); // calls function
                break;
                //Break to return back to menu
        }
        std::cout << std::endl << "Press enter to continue?";
        //ignores the enter key pressed previously.
        std::cin.ignore();
        
        
        
    }
    
}


//function for selling coffee
void CoffeeShop::sellCoffee(int type, int amount)
{
    //if parseString.first = 1, 2, or 3 this funcitons will get ran
    switch(type)
    {
        case 1: //calculates small coffee size
            profit += sPrice * amount;     //running total of profit
            tsSold += amount;     //running total of cups sold
            sOunce += small * amount;     // running total of ounces sold
            std::cout << std::fixed << std::showpoint << std::setprecision(2);// output cleaner
           std::cout << "The price of this purchase is $" << sPrice * amount << std::endl;//outputs price of purchase
            break;
        case 2: //calculates medium coffee size
            profit += mPrice * amount;     //running total of profit
            tmSold += amount;       //running total of cups sold
            mOunce += medium * amount;       // running total of ounces sold
            std::cout << std::fixed << std::showpoint << std::setprecision(2); // makes it look cleaner
            std::cout << "The price of this purchase is $" << mPrice * amount << std::endl; // outputs price of purchase
            break;
        case 3: // calculates large coffee size.
            profit += lPrice * amount;      //running total of profit
            tlSold += amount;      //running total of cups sold
            lOunce += large * amount;       // running total of ounces sold
            std::cout << std::fixed << std::showpoint << std::setprecision(2); // make it look nicer
            std::cout << "The price of this purchase is $" << lPrice * amount << std::endl;// outputs price of purchase
            break;

    }
}
    

//this function output for the number of cups sold of each size and total
void CoffeeShop::cupsSold()
{
    std::cout << "You have sold " << tsSold << " small coffees." << std::endl;
    std::cout << "You have sold " << tmSold << " medium coffees." << std::endl;
    std::cout << "You have sold " << tlSold << " large coffees." << std::endl;
    std::cout << "The total cups of coffee sold is " << tsSold + tmSold + tlSold << "." << std::endl; //total is sum of all 3
}

//this function output for the amount in ounces sold of each size and total
void CoffeeShop::amountSold()
{
    std::cout << "Ounces of small coffee sold: " << sOunce << "." << std::endl;
    std::cout << "Ounces of medium coffee sold: " << mOunce << "." << std::endl;
    std::cout << "Ounces of large coffee sold: " << lOunce << "." << std::endl;
    std::cout << "The total ounces of coffee sold is " << sOunce + mOunce + lOunce << "." << std::endl; // total is sum of all 3
}

//this function output for money made of each size and total money made
void CoffeeShop::moneyMade()
{
    //Set precision to make the output look nice
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "Profit on small coffees is $" << tsSold * sPrice << "." << std::endl;
    std::cout << "Profit on medium coffee is $" << tmSold * mPrice << "." << std::endl;
    std::cout << "Profit on large coffee is $" << tlSold * lPrice << "." << std::endl;
    std::cout << "The total profit is $" << (tlSold * lPrice) + (tmSold * mPrice) + (tsSold * sPrice) << "." << std::endl;//total is the sum of all 3 sizes
}

//this gets ran to evaluate the 2 intergers entered by the user and runs depending on what user entered.
std::pair<int, int> CoffeeShop::parseString(const std::string &TypeAmount)
{
    std::istringstream iss(TypeAmount);
    
    std::string tempType;
    std::getline(iss, tempType, ',');
    
    std::string tempAmount;
    std::getline(iss, tempAmount);
    
    int type;
    std::istringstream(tempType) >> type;
    
    int amount;
    std::istringstream(tempAmount) >> amount;
    
    return std::pair<int, int>(std::move(type), std::move(amount));
}


