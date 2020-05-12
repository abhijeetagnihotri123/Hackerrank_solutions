#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k;
    cin>>n>>k;
    int *a=new int[n];
    vector<int>ICL;
    vector<int>NICL;
    int c1=0;
    int c2=0;
    int t;
    int total=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>t;
        if(t==1)
        {
            ICL.push_back(a[i]);
            c1++;
        }
        else
        {
            NICL.push_back(a[i]);
            c2++;
        }
    }
    delete(a);
    sort(ICL.begin(),ICL.end());
    sort(NICL.begin(),NICL.end());
    if(c1==0)
    {
        for(int i=0;i<c2;i++)
        {
            total+=NICL[i];
        }
    }
    else if(c1 <= k)
    {
        for(int i=0;i<c1;i++)
        {
            total+=ICL[i];
        }
        for(int i=0;i<c2;i++)
        {
            total+=NICL[i];
        }
    }
    else if(c1>k)
    {
        for(int i=0;i<c1-k;i++)
        {
            total-=ICL[i];
        }
        for(int i=c1-k;i<c1;i++)
        {
            total+=ICL[i];
        }
        for(int i=0;i<c2;i++)
        {
            total+=NICL[i];
        }
    }
    cout<<total;
    return 0;
}