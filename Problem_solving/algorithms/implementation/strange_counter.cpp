#include <iostream>
using namespace std;
int main()
{   
    long t;
    cin>>t;
    long c=3;
    while(t>c)
    {
        t=t-c;
        c=c*2;
    }
    cout<<(c-t+1);
    return 0;
}

