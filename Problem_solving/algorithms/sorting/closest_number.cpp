#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    sort(a.begin(),a.end());
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(m[a[i]]==1){c++;}
    }
    if(c!=n)
    {
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                cout<<a[i]<<" "<<a[i+1]<<" ";
                i++;
            }
        }
    }
    else if(c==n)
    {
        int Min=a[n-1]-a[0];
        for(int i=0;i<n-1;i++)
        {
            if((a[i+1]-a[i]) < Min)
            {
                Min=a[i+1]-a[i];
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if((a[i+1]-a[i])==Min)
            {
                cout<<a[i]<<" "<<a[i+1]<<" ";
            }
        }
    }
    else{;}
    return 0;
}

