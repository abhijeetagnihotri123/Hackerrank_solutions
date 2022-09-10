#include <iostream>

using namespace std;

class Base
{
    private:
        int value;
    public:
        Base():value{0}
        {
            cout<<"Base default constructor called"<<endl;
        }
        Base(int x) : value{x}
        {
            cout<<"Base parameterized Constructor Called"<<endl;
        }
        ~Base()
        {
            cout<<"Base Destructor"<<endl;
        }
};
class Derived:public Base
{
    private:
        int double_value;
    public:
        Derived():Base(),double_value{0}
        {
            cout<<"Derived no-args constructor"<<endl;
        }
        Derived(int x):Base(x),double_value{x<<1}
        {
            cout<<"Derived parameterized constructor"<<endl;
        }
        ~Derived()
        {
            cout<<"Derived destructor"<<endl;
        }
};
int main()
{
    Derived d{1000};
    return 0;
}