#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,m;
    vector<int>a;
    cin>>n>>m;
    int k;
    for(int i=0;i<m;i++)
    {
        cin>>k;
        a.push_back(k);
    }
    if(n==m)
    {
        cout<<0;
    }
    else
    {   
        sort(a.begin(),a.end());
        int max=n-1-a[m-1];
        int ref;
        for(int i=1;i<m;i++)
        {
            if(max<(a[i]-a[i-1])/2)
            {
                max=(a[i]-a[i-1])/2;
            }
        }
        cout<<max;
    }
    return 0;
}   
