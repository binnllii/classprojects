//value returning function is vowel

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//set vars



//isVowel function if is a vowel return true else return false
bool isVowel(char letter)
{
    if ((letter == 'a') || (letter == 'e') ||  (letter == 'i') || (letter == 'o') || (letter == 'u'))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    //Set empty string
    
    string word = " ";
    
    //ask for user input
    
    cout << "Please enter a word: ";
    cin >> word;
    
    //set vowel count to 0
    
    int vowels = 0;
    
    //when i is less than word.size vowels count goes + 1 and i count goes +1
    
    for(int i = 0; i < (int)word.size(); i++)
    {
        char testing = word.at(i);
        if(true == isVowel(testing))
        {
            vowels++;
        }
    }
    
    //finally output the count of the vowels in the word
    
    cout << "The number of vowels in the word is " << vowels << "." << endl;
    
        
}


//global const zero as 0
const int zero = 0;
double readDouble();

//this function reverses the digits

int reverseDigits(int nom)
{
    int num = 0;
    
    //if nom is negative this is what we do to the number
    
    if(nom < 0)
    {
        
        //take the absolute of the number because it is less than 0
        
        nom = abs(nom);
        
        while(nom > zero)
        {
            
        //first we take the num and we mulitply it by 10 which will always be 0 because of the variable num = 0, we gave in the beginning, then we take that and mod it by 10 to get the remainder which will always be the last number. then we take nom and divide it by 10, it automatically takes the floor of the function because it is set as an integer, then we repeat until all the numbers are gone, we return num in between every sequence
            
            num = num * 10 + nom % 10;
            nom = nom / 10;
        }
        
        //we can divide or multiply by -1 to get the number back to a negative.
        
        return num / -1;
    }
    
    //else we just run the normal code without dividing by negative or taking the absolute of the number
    
    else
    {
        while(nom > zero)
        {
            
        //first we take the num and we mulitply it by 10 which will always be 0 because of the variable num = 0, we gave in the beginning, then we take that and mod it by 10 to get the remainder which will always be the last number. then we take nom and divide it by 10, it automatically takes the floor of the function because it is set as an integer, then we repeat until all the numbers are gone, we return num in between every sequence
            
            num = num * 10 + nom % 10;
            nom = nom / 10;
        }
        return num;
    }
}


int main()
{
    //set var
    
    int number;
    
    //ask for user input
    
    cout << "Please enter an integer: ";
    number = readDouble();
    
    //cin >> number;

    //cout the reverseDigits function.
    
    cout << reverseDigits(number) << endl;
    return 0;
}

//if the input isnt a number we will run this function until they enter a number.

double readDouble()
{
    double no = 0;
    cin >> no;
    
    // Test if the input stream has entered the 'fail' state.
    // This would happen if the input was not a valid number of type double.
    
    while (cin.fail())
    {
        cin.clear();            // Clear the fail flag.
        cin.ignore(1000, '\n');  // Skip the rest of the line with the error.
        
        cout << "Please enter a valid number." << endl;
        cout << "Please try again: ";
        cin >> no;
    }
    return no;
}













//NEVER GOING TO USE
//# include <iostream>
//using namespace std ;
//
//int reverseDigit ( int num )
//{
//    int rev ;
//    while ( num > 0)
//    { rev = rev * 10 + num % 10 ;
//        num = num / 10 ;
//    }
//    return rev ;
//}
//
//int main ()
//{
//    int x ;
//    cout << " enter a number plz " << endl ;
//    cin >> x;
//    cout << reverseDigit (x) << endl ;
//    }






//NEVER GOING TO USE
//    int nom = 0;
//    cout << "Please enter a number: " ;
//    cin >> nom;
//
//
//    for(int i = (int)nom.size(); i > 0; i--)
//    {
//        cout << nom;
//    }
//}

