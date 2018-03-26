//lab5
//read list of numbers and print the sum of all even and odd numbers

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;



//#1
const int NOM = -999;
int main ()
{
    //def variables

    int integers = 0;
    int even = 0;
    int odd = 0;
    //ask for user input
    cout << "Enter integers seperated by returns/enter keys then enter -999 to return results: " << endl;
//    cin >> integers;
    //create the while loop to seperate the even with odds.
    while (integers != NOM)
    {
        cin >> integers;
        if (integers % 2 == 0)
        {
            even = even + integers;
        }
        else
        {
            odd = odd + integers;
        }
        
       
    }
    //return the results
        cout << "The sum of odd numbers is " << odd + 999 << endl;
        cout << "The sum of even numbers is " << even << endl;
}

/*a. Prompt the user to input two integers: firstNum and secondNum (firstNum must be less than
 secondNum).
 b. Output all odd numbers between firstNum and secondNum.
 c. Output the sum of all even numbers between firstNum and secondNum.
 d. Output the numbers and their squares between 1 and 10. (This has nothing to do with the user
 input.)
 e. Output the sum of the square of the odd numbers between firstNum and secondNum.
 f. Output all uppercase letters. (This also has nothing to do with user input.)*/


/*if first number is less than second number 
 */

//#2b
int main ()
{
    // set variables
    int firstNum, secondNum;
    cout << "Input 2 numbers seperated by spaces (the second number must be greater than the first: " << endl;
    cin >> firstNum >> secondNum;
    //if odd print it +2 if even print it + 1 so it will always print odd number
    while (firstNum <= secondNum - 3)
    {
        if (firstNum % 2 == 1)
        {
            firstNum = firstNum + 2;
        }
        if (firstNum % 2 == 0)
        {
            firstNum = firstNum + 1;
        }
        //output results
        cout << firstNum << " ";
        
    }
    
}

/* 102 104 106 should add to 312
 take in the numbers
 100 108
 newnum = 102
 */
 
//#2c
int main ()
{
    //set variables
    int firstNum = 0, secondNum, newNum;
    cout << "Input 2 numbers seperated by spaces (the second number must be greater than the first: " << endl;
    cin >> firstNum >> secondNum;
    newNum = firstNum + 2;
    firstNum = firstNum + 2;
    //make the while loop
    while (newNum < secondNum - 2)
    {
        // if its an even number
        if (firstNum % 2 == 0) {
            firstNum = firstNum + newNum + 2;
            newNum = newNum + 2;
            //cout << firstNum << " ";
        }
        //if its an odd number turn it back to an even.
        else {
            firstNum = firstNum - 1;
            newNum = newNum - 1;
            
        }
        //cout << firstNum << endl;
    }
    //output
        cout << firstNum << endl;

}

 
//#2d
int main ()
{
    //set variables
    int nom = 1;
    //while nom is less than or equal to 10
    while (nom <= 10)
    {
        //include math on the top
        //nom = pow(nom, 2);
        //nom = nom + 1;
        //print the numer and number to power of 2
        cout << nom << " ";
        cout << pow(nom,2) << endl;
        nom = nom + 1;

    }
}


//121 + 169 + 225 + 289 + 361 = 1165
 
//#2e
int main ()
{
    //set variables
    int firstNum, secondNum, superNum = 0;
    cout << "Input 2 numbers seperated by spaces (the second number must be greater than the first: " << endl;
    cin >> firstNum >> secondNum;
    //superNum = secondNum;
    //create while loop
    //if even then do something if odd then set back to even
    //creat new var superNum to store the total amount
    while (secondNum > firstNum + 2)
    {
        if (secondNum % 2 == 1)
        {
            secondNum = secondNum - 2;
            superNum = superNum + pow(secondNum, 2);
            
        }
        if (secondNum % 2 == 0)
        {
            superNum = secondNum;
            secondNum = secondNum - 1;
            superNum = superNum - 1;
            superNum = pow(superNum, 2);
        }
        //output
        cout << superNum << endl;
    }

}

//#2f
int main ()
{
    //variable letter
    char letters;
    //initialize char to 'A'
    letters = 'A';
    //create the while loop
    while (letters <= 'Z')
    {
        //output
        cout << letters << endl;
        //letters increase by 1 while letter is less than z
        letters++;
    }
    
}


