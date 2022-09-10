#include "Checking_Account.h"
using namespace std;

Checking_Account::Checking_Account(string name,double def_balance)
    :name{name},balance{def_balance}
{
    cout<<"Checking account opened for "<<name<<endl;
}

bool Checking_Account::deposit(double amount)
{   
    if(amount < 0)
    {
        cout<<"Cannot deposit\n";
        return false;
    }
    this->balance += amount;
    return true;
}
bool Checking_Account::withdraw(double amount)
{
    amount += this->per_check_fee;
    if(this->balance >= amount)
    {
        this->balance -= amount;
        return true;
    }
    cout<<"Insufficient Funds\n";
    return false;
}
Checking_Account::~Checking_Account()
{
    cout<<"Closing checking Account\n";
}
ostream &operator<<(ostream &os,const Checking_Account &account)
{
    os << "[Checking_Account: " << account.name << ": " << account.balance  << "]";
    return os;
}
