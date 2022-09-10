#include <iostream>
#include <string>
#include <exception>
using namespace std;

class DivideByZero : public exception
{       
    public: 
    DivideByZero():exception(){}
    virtual const char *what()
    {
        return "Arithemetic exception :/zero";
    }
    virtual ~DivideByZero()=default;
};
class NegativeParameter:public exception
{       
    public: 
        NegativeParameter():exception(){}
        virtual const char *what()
        {
            return "Invalid Parameter";
        }
        virtual ~NegativeParameter() = default;
};
double MPG(int miles,int gallons)
{
    if(miles < 0 || gallons < 0)
    {   
        throw NegativeParameter();
    }
    if(gallons == 0)
    {
        throw DivideByZero();
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
    catch(NegativeParameter& e)
    {
        std::cerr << e.what() <<endl;;
    }
    catch(DivideByZero& e)
    {
        std::cerr << e.what() <<endl;
    }
    return 0;
}