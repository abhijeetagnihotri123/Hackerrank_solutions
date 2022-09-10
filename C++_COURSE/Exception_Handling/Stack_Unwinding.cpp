#include <iostream>
using namespace std;

void func_a(void);
void func_b(void);
void func_c(void);

int main()
{   
    func_a();
    return 0;
}
void func_a(void)
{
    cout<<"In Function A\n";
    func_b();
    cout<<"Func_a ending\n";
}
void func_b(void)
{
    cout<<"In Function B\n";
    try
    {
        func_c();
    }
    catch(int &e)
    {
        cerr << e << endl;
    }
    cout<<"Func_b ending\n";
}
void func_c(void)
{
    cout<<"In Function C\n";
    try
    {
        throw 100;
    }
    catch(int &e)
    {
        cerr << e << '\n';
    }    
    cout<<"Func_c ending\n";
}