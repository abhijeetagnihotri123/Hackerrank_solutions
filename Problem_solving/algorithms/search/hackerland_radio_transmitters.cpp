#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0;
    int j;
    int c=0;
    int x;
    while(i<n)
    {
        j=i+1;
        while(j<n && (v[i]+k)>=v[j])
        {
            j++;
        }
        x=j;
        j--;
        while(x<n && (v[j]+k)>=v[x])
        {
            x++;
        }
        c++;
        i=x;
    }
    cout<<c;
    return 0;
}
