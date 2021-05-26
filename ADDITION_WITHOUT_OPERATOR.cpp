#include <iostream>
using namespace std;

int add_without_operator(int,int);

int main()
{       
    int a,b;
    cin>>a>>b;
    cout<<add_without_operator(a,b);
    return 0;
}

int add_without_operator(int a,int b)
{
    if(b == 0){
        return a;
    }
    int sum = a ^ b;
    int carry = (a&b)<<1;
    return add_without_operator(sum,carry);
}