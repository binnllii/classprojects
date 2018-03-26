#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
public:
    //constructors -
    BankAccount();
    BankAccount(double initAmount);
    
    //destructor
    
    
    //member functions
    double getBalance();
    void deposit(double amount);
    bool withdraw(double amount);
    
    //static functions
    static int getMAXBalance();
private:
    //instance variable
    double balance;
    
    //class variable
    static const int MAX = 10000;
};
#endif