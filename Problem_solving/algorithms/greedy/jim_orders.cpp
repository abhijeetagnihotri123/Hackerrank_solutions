#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int max=0;
    int *b,*c;
    b=new int[n];
    c=new int[n];
    for(int i=1;i<=n;i++)
    {
        
        cin>>b[i-1]>>c[i-1];
        if(max<b[i-1]+c[i-1])
        {
            max=b[i-1]+c[i-1];
        }
    }
    vector<vector<int>>a(max+1);
    for(int i=1;i<=n;i++)
    {
        a[b[i-1]+c[i-1]].push_back(i);
    }
    for(int i=0;i<=max;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
        cout<<a[i][j]<<" ";
        }
    }
    return 0;
}
