#include <iostream>
using namespace std;

int thief(int *a,int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return a[0];
    }
    else if(n==2)
    {
        return a[0]>a[1]?a[0]:a[1];
    }
    else
    {
        int dp[n];
        dp[0]=a[0];
        dp[1]=max(a[0],a[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = (a[i]+dp[i-2]>dp[i-1])?(a[i]+dp[i-2]):dp[i-1];
        }
        return dp[n-1];
    }
}
int main()
{   
    int n;
    cin>>n;
    int *a;
    a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<thief(a,n);
    return 0;
}