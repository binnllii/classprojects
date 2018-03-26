#include "bankAccount.h"
BankAccount::BankAccount()
{
    balance = 0;
}


double BankAccount::getBalance()
{
    return balance;
}

void BankAccount::deposit(double amount)
{
    balance += amount;
}

bool BankAccount:: withdraw(double amount)
{
    if(amount > balance)
    {
        return false;
    }
    balance -= true;
    return true;
}

int BankAccount::getMAXBalance()
{
    return MAX_BALANCE;
}