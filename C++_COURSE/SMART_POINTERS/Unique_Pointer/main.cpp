#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"Default Constructor of A\n";
    }
    virtual void w()
    {
        cout<<"In A\n";
    }
    virtual ~A()
    {
        cout<<"Destructor of A\n";
    }
};
class B:public A
{
    public:
        B():A()
        {
            cout<<"Default Constructor of B\n";
        }
        virtual void w() override final
        {
            cout<<"In B\n";
        }
        ~B()
        {
            cout<<"Destructor of B\n";
        }
};
int main()
{   
    unique_ptr<A> p1 = make_unique<A>();
    unique_ptr<A> p2 = make_unique<B>();
    p1->w();
    p2->w();
    return 0;
}