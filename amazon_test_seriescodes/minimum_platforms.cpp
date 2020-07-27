#include <bits/stdc++.h>
using namespace std;
int findPlatform(int a[],int d[],int n)
{
    
}
int main()
{   
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        cout<<findPlatform(a,b,n)<<endl;
    }
    return 0;
}