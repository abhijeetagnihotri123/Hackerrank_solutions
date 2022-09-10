#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"
using namespace std;

class Trust_Account:public Savings_Account
{
    friend ostream &operator<<(ostream &os,const Trust_Account &);
    private:    
        double def_balance = 0.0;
        double def_int_rate = 0.0;
        double bonus_amount = 50.0;
        double bonus_threshold = 5000.0;
        int max_withdrawals = 3;
        double max_withdraw_percent = 0.2;
    protected:
        int num_withdrawals;
    public:
        Trust_Account(string name = "Untitled",  double balance = 0.0, double int_rate = 0.0);
        bool deposit(double);
        bool withdraw(double);
        ~Trust_Account(){cout<<"Trust Account closed"<<endl;}
};

#endif