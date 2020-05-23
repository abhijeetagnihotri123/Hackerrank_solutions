#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,m,a,b,k;
    long int max;
    cin>>n>>m;
    vector<long int>v(n+1,0);
    while(m--)
    {
        cin>>a>>b>>k;
        v[a]+=k;
        if((b+1)<=n)
        {
        v[b+1]-=k;
        }
    }
    max=v[1];
    for(int i=2;i<=n;i++)
    {
        v[i]+=v[i-1];
        if(max < v[i])
        {
            max=v[i];
        }
    }
    cout<<max;
    v.clear();
    return 0;
}
