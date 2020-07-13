#include <iostream>
using namespace std;

long long countWays(int m)
{
    if(m==1)
    {
        return 1;
    }
    else if(m==2)
    {
        return 2;
    }
    else
    {
        long long ways[m+1];
        ways[0]=1;
        ways[1]=1;
        ways[2]=2;
        for(int i=3;i<=m;i++)
        {
            ways[i]=ways[i-1]+ways[i-2]-ways[i-3];
        }
        return ways[m];
    }
}
int main()
{   
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}