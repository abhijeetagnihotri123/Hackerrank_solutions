#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    vector<int>a(n,0);
    vector<int>b(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]]=i;
    }   
    int swaps=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i+1)
        {   
            swaps++;
            int t=a[i];
            a[i]=i+1;
            a[b[i+1]]=t;
            b[t]=b[i+1];
        }
    }
    cout<<swaps;
    a.clear();
    b.clear();
    return 0;
}
