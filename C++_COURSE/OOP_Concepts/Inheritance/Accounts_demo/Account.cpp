#include "Account.h"

using namespace std;
Account::Account(double balance)
    :balance{balance}
{
    cout<<"Account with "<<balance<<" Opened"<<endl;
}

void Account::Deposit(double amount)
{
    balance += amount;
}
void Account::withdraw(double amount)
{
    if(amount > balance)
    {
        cout<<"Insufficient Balance"<<endl;
    }
    else
    {
        balance -= amount;
    }
}
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os <<  "Account balance: " << account.balance;
    return os;
}
