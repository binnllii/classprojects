
//sources: https://answers.yahoo.com/question/index?qid=20150401205219AAzeEn5

/*******************************************************/
/*** Lab 8                                                            **/
/*** Find the smallest index of an array                       **/
/*** turn a string from lower to upper                               **/
/*** by Bin Li                                                              **/
/*******************************************************/

/*1. Write	a	C++	function,	smallestIndex,	that	takes	as	parameters	an	int array	and	its	size	and returns	the	index	of	the	smallest	element	in	the	array.	 Also write	a program to test your function.
 */

//#1

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int smallestIndex(int index[], int number);

int main()
{
    const int arraySize = 10; // sets const array to 10
    int test[arraySize] {10,11,90,30,12,0,43,40,4,7}; // the # values of the array
    //variables
    int i = 0, smallSize;
    cout << "The array numbers are " << endl; // print the array numbers using a for loop
    for (i = 1; i < arraySize; i++)
    {
        cout << test[i] << endl;
    }
    smallSize = smallestIndex(test, arraySize); // small size
    cout << "The smallest number in the list is " << test[smallSize] << "." << endl; // the actual smallest number is the position at which the return value of smallest index. ex: test[##]
    cout << "The position of the smallest number is " << smallSize << "." <<endl; // the position is the return value of the smallestIndex function
}

//function to find the smallest numbers position in the array
int smallestIndex(int index[], int number)
{
    // find the smallest element of the array.
    int num = 0, i = 0;
    for (i = 1; i < number; i++)
    {
        if (index[i] < index[num])
            num = i; // num will keep track of the position of which the smallest number is in.
    }
    return num;
    
}

//---------------------------------------------------------------------------------------------------

//#2

// 2. Write a	program	that	prompts	the	user to	input	a	string	and	outputs	the	string	in	uppercase
//letters. You must use	a	character	array to store the string.*/


#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;




//size_t represents size and counts max character = 100
const size_t maxLen = 100;

int main()
{
    int i = 0; // set var i = 0
    char str[maxLen];
    cout << "Enter a String less than 100 characters: "; // prompt user to enter a string less than 100 char
    cin.get(str, sizeof(str)); // gets char less than 100 chars. size of set to 100.
    
    
    //for loop for turning lower to upper.
    for (i = 0; (i < maxLen) && (str[i] != '\n'); i++)
    {
        str[i] = toupper(str[i]);
    }
    //prints results of the loop
    cout << "The upper case of this sentence is: " << str << endl;
    

}













