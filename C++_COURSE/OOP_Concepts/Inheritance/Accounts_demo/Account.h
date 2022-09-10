#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>


class Account
{
    friend std::ostream &operator<<(std::ostream &,const Account &);
    protected:
        double balance;
    public:
        Account(double);
        void Deposit(double);
        void withdraw(double);
};
#endif