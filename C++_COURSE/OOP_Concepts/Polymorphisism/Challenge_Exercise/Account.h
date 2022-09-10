#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Account
{       
    friend ostream &operator<<(ostream &os,const Account &Account)
    {
        return os;
    }
    public:
        virtual bool deposit(double) = 0;
        virtual bool withdraw(double) = 0;
        virtual ~Account(){}
};
#endif
