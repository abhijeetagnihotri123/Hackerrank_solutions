#include <iostream>
using namespace std;
int max(int &a,int &b)
{
    return a>=b?a:b;
}
int main()
{   
    int n;
    cin>>n;
    int *a,*dp;
    a = new int[n];
    dp = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n == 0)
    {
        cout<<"No maximum sum possible"<<endl;
    }
    else if(n == 1)
    {
        cout<<a[0]<<endl;
    }
    else if(n == 2)
    {
        cout<<max(a[0],a[1]);
    }
    else
    {
        dp[0] = a[0];
        dp[1] = max(a[0],a[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(a[i]+dp[i-2],dp[i-1]);
        }
        cout<<dp[n-1];
    }
    delete(dp);
    delete(a);
    return 0;
}