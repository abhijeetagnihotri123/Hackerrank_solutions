#include "Savings_Account.h"
using namespace std;

Savings_Account::Savings_Account(string name,double balance,double int_rate)
    :name{name},balance{balance},int_rate{int_rate}
{
    cout<<"Savings bank account opened for "<<name<<endl;
}
bool Savings_Account::deposit(double amount)
{
    if(amount < 0)
    {   
        cout<<"Negative amount cannot be deposited\n";
        return false;
    }
    amount *= (1+int_rate/100);
    this->balance += amount;
    return true;
}
bool Savings_Account::withdraw(double amount)
{
    if(this->balance>=amount)
    {
        this->balance -= amount;
        return true;
    }
    cout<<"Insufficient Balance\n";
    return false;
}
Savings_Account::~Savings_Account()
{
    cout<<"Savings account is being closed now for "<<name<<endl;
}
ostream &operator<<(ostream &os,const Savings_Account &account)
{
    os <<"[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "]";
    return os;
}