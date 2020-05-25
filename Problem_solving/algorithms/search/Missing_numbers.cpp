#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    vector<int>arr(n);
    map<int,int>m1;
    map<int,int>m2;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        m1[arr[i]]++;
    }
    cin>>m;
    vector<int>brr(m);
    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
        m2[brr[i]]++;
    }
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    int i=0;
    while(i<n)
    {
        if(m1[arr[i]]==m2[arr[i]]){;}
        else
        {
            cout<<arr[i]<<" ";
        }
        i=i+m1[arr[i]];
    }
    return 0;
}

