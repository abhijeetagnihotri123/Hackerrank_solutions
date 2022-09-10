
#include <iostream>
#include <vector>

using namespace std;

class Account
{   
    public:
    virtual void withdraw(double amount)
    {
        cout<<"Account Class "<<amount<<" \n";
    }
    Account()
    {
        cout<<"Account Constructor\n";
    }
    virtual ~Account()
    {
        cout<<1<<" Account Destructor\n";
    }
};
class Checking:public Account
{
    public:
    void withdraw(double amount)
    {
        cout<<"Checking Class "<<amount<<" \n";
    }
    Checking()
    {
        cout<<"Checking Account Constructor\n";
    }
    ~Checking()
    {
        cout<<2<<" Checking Account Destructor\n";
    }
};
class Savings:public Account
{
    public:
    void withdraw(double amount)
    {
        cout<<"Savings Class "<<amount<<" \n";
    }
    Savings()
    {
        cout<<"Savings Account Constructor\n";
    }
    ~Savings()
    {
        cout<<3<<" Savings Account Destructor\n";
    }
};
class Trust:public Account
{
    public:
    void withdraw(double amount)
    {
        cout<<"Trust Class "<<amount<<" \n";
    }
    Trust()
    {
        cout<<"Trust Account Constructor\n";
    }
    ~Trust()
    {
        cout<<4<<" Trust Account Destructor\n";
    }
};
int main()
{       
    
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    
    std::cout << "\n === Array ==== " << std::endl;
    Account *array [] = {p1,p2,p3,p4};
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);
        
    std::cout << "\n === Array ==== " << std::endl;
    array[0] = p4;
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);

    std::cout << "\n === Vector ==== " << std::endl;
    std::vector<Account *> accounts {p1,p2,p3,p4};
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);
        
    std::cout << "\n === Vector ==== " << std::endl;
    accounts.push_back(p4);
    accounts.push_back(p4);
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;


    {
        Trust p5;
        Account &p6 = p5;
        p5.withdraw(1000);
    }
    return 0;
}