/* A header file for BankAccount class definition.

   Written by: Li Liang
   Date: 09/20/2009

   Sources: None
*/

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount
{
public:
	//constructors
	BankAccount();
	BankAccount(double initBalance);

	//accessor functions
	double getBalance() const;
	void print() const;

	//mutator functions
	void deposit(double amount);
	bool withdraw(double amount);

private:
	double	balance;
}; //pay attention to this ';'!

#endif