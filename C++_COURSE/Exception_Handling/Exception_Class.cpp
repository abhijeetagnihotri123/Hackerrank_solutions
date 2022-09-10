#include <iostream>

using namespace std;

class DivideByZero
{   
    public:
    DivideByZero()
    {
        cout<<"/by zero\n";
    }
    ~DivideByZero()
    {
        cout<<"Destroying the divide by zero\n";
    }
};
class NegativeValue
{
    public:
    NegativeValue()
    {
        cout<<"Not valid value\n";
    }
    ~NegativeValue()
    {
        cout<<"Destroying exception object\n";
    }
};
double MPG(int miles,int gallons)
{
    if(gallons == 0)
    {
        throw DivideByZero();
    }
    if(gallons < 0 || miles < 0)
    {
        throw NegativeValue();
    }
    return static_cast<double>(miles)/gallons;
}
int main()
{   
    int miles{};
    int gallons{};
    cin>>miles>>gallons;
    try
    {
        cout<<MPG(miles,gallons)<<endl;
    }
    catch(DivideByZero &e)
    {
        cerr <<"Sorry, you can't divide by zero" <<endl;
    }
    catch(NegativeValue &e)
    {
        cerr <<"Sorry, you can't enter negative parameters"<<endl;
    }
    cout<<"Program executed successfully\n";
    return 0;
}