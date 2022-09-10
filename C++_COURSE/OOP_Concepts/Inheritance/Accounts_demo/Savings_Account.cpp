#include "Savings_Account.h"

using namespace std;

Savings_Account::Savings_Account(double balance,double rate):Account(balance)
{   
    this->int_rate = rate;
    cout<<"Parameterized Constructor"<<endl;
}
Savings_Account::Savings_Account(void)
    :Savings_Account{0.0,0.0}
{
    cout<<"Zero balance Account opened"<<endl;
}
void Savings_Account::deposit(double amount)
{
    amount *= (1+int_rate/100);
    Account::Deposit(amount); 
}
std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate;
    return os;
}