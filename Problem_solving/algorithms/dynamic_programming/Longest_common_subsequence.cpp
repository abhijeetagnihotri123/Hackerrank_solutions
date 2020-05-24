#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,m;
    cin>>n>>m;
    int **C,*a,*b;
    C=new int*[n+1];
    a=new int[n];
    b=new int[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<m;j++)
    {
        cin>>b[j];
    }
    for(int i=0;i<=n;i++)
    {
        C[i]=new int[m+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                C[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                C[i][j]=1+C[i-1][j-1];
            }
            else
            {
                C[i][j]=max(C[i-1][j],C[i][j-1]);
            }
        }
    }
    int i=n;
    int j=m;
    int index=C[n][m];
    vector<int>lcs;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            lcs.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(C[i-1][j]>C[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i=lcs.size()-1;i>=0;i--)
    {
        cout<<lcs[i]<<" ";
    }
    for(int i=0;i<=n;i++)
    {
        delete(C[i]);
    }
    delete(C);
    delete(a);
    delete(b);
    return 0;
}
