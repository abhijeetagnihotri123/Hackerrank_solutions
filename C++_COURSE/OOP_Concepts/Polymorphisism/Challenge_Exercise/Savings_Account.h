#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"
using namespace std;

class Savings_Account:public Account
{   
    friend ostream &operator<<(ostream &,const Savings_Account &);
    protected:
        string name;
        double balance;
        double int_rate;
    public:
        Savings_Account(string,double,double);
        bool deposit(double); 
        bool withdraw(double); 
        virtual ~Savings_Account();
};

#endif

