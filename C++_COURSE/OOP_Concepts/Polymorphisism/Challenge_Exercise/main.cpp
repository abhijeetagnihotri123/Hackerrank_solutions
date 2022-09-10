#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_util.h"
using namespace std;

int main()
{   
    vector<Account*> sav_accounts;
    sav_accounts.push_back(new Savings_Account {"Wonderwoman1", 5001, 5.1} );
    sav_accounts.push_back(new Savings_Account {"Wonderwoman2", 5002, 5.2} );
    sav_accounts.push_back(new Savings_Account {"Wonderwoman3", 5003, 5.3} );
    sav_accounts.push_back(new Savings_Account {"Wonderwoman4", 5004, 5.4} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking
   
    vector<Account*> check_accounts;
    sav_accounts.push_back(new Checking_Account {"SuperMan1", 5001} );
    sav_accounts.push_back(new Checking_Account {"SuperMan2", 5002} );
    sav_accounts.push_back(new Checking_Account {"SuperMan3", 5003} );
    sav_accounts.push_back(new Checking_Account {"SuperMan4", 5004} );


    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    // vector<Trust_Account> trust_accounts;
    // trust_accounts.push_back(Trust_Account {} );
    // trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0} );
    // trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0} );
    // trust_accounts.push_back(Trust_Account {"Aramis", 30000} );

    // display(trust_accounts);
    // deposit(trust_accounts, 1000);
    // withdraw(trust_accounts, 3000);
    
    // // Withdraw 5 times from each trust account
    // // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    // for (int i=1; i<=5; i++)
    //     withdraw(trust_accounts, 1000);
    return 0;
}