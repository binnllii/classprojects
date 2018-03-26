/* This program demonstrates how to define class and use objects.

   Written by: Li Liang
   Date: 09/29/2009

   Sources: None
*/

#include <iostream>     
#include "BankAccount.h"
#include "InputTools.h"

using namespace std; 

int main()
{
	//create objects
	BankAccount		account1;
	BankAccount		account2(100);
	double			amount;

	//use objects
	cout << endl << "account1's state: ";
	account1.print();

	cout << endl << "account1's state: ";
	account2.print();

	amount = readDouble("\nPlease enter the amount you want to deposit in account1: ");
	account1.deposit(amount);
	cout << endl << "Current Balance in account1: $" << account1.getBalance();

	amount = readDouble("\nPlease enter the amount  you want to withdraw from account2: ");
	if(account2.withdraw(amount))
		cout << endl << "Current Balance in account2: $" << account2.getBalance() << endl;
	else
		cout << endl << "Sorry, you don't have enough funding." << endl;
	
	return 0;
}

