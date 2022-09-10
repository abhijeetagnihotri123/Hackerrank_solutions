#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"
using namespace std;


class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    string name = "Unnamed Checking Account";
    double balance = 0.0;
    double per_check_fee = 1.5;
public:
    Checking_Account(void);
    Checking_Account(string, double balance);    
    bool withdraw(double);
    bool deposit(double);
    ~Checking_Account();
};

#endif