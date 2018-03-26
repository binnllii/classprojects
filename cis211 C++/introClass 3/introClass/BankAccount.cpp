/* The implementation file for BankAccount class.

   Written by: Li Liang
   Date: 09/29/2009

   Sources: None
*/

#include <iostream> 
#include "BankAccount.h"

using namespace std; 

/* Default constructor. 
   It initialize balance to 0. 
*/
BankAccount::BankAccount() 
{
	balance = 0;
}

/* A constructor. 
   in: initBalance
   It initialize balance to the passed in initBalance. 
*/
BankAccount::BankAccount(double initBalance)
{
	balance = initBalance;
}

/* It returns the current balance of the BankAccount object.
   return: current balance.
*/
double BankAccount::getBalance() const
{
	return balance;
}

/* It prints the current object state to the standard out.
*/
void BankAccount::print() const
{
	cout << "Balance-- $" << balance << endl;
}

/* It deposits the passed in amount.
   in: amount
*/
void BankAccount::deposit(double amount)
{
	balance += amount;
}

/* It withdraws the passed in amount.
   in: amount
   return: true if the withdraw is successful, the balance will be modified
           false if the balance < amount, balance won't be modified.
*/
bool BankAccount::withdraw(double amount)
{
	if(balance >= amount)
	{
		balance -= amount;
		return true;
	}
	return false;
}