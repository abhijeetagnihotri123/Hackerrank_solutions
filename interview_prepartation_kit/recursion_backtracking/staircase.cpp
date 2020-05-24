#include <bits/stdc++.h>
using namespace std;
int count_steps(int&);
int main()
{   
    int s,n;
    cin>>s;
    int c;
    while(s--)
    {   
        c=0;
        cin>>n;
        cout<<count_steps(n)<<endl;
    }    
    return 0;
}
int count_steps(int &n)
{
    vector<unsigned int>a(n+1,0);
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    return a[n];
}
