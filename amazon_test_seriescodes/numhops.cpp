#include <iostream>
using namespace std;
long long countWays(int&);
int main()
{   
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}
long long countWays(int &n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else if(n == 3)
    {
        return 4;
    }
    else
    {
        long long a,b,c,d;
        a = 1;
        b = 2;
        c = 4;
        for(int i=3;i<=n;i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }   
    return b%(1000000000+7);
    }
}