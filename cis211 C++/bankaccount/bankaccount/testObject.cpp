#include <iostream>
using namespace std;
#include "myutil.h"
#include "bankAccount.h"

int main()
{
    BankAccount a1, a2;

    
    a1.deposit(100);
    a2.deposit(1000);
    if (a1.withdraw(20))
    {
        cout << "withdraw 20 successfully!" << endl;
        
    }
    else
    {
        cout << "balence too low" << endl;
    }
    cout << "Current balance in a1: " << a1.getBalance() << endl;
    cout << "Current balance in a2: " << a2.getBalance() << endl;
    
}
