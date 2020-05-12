#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,r;
    cin>>n>>m>>r;
    int a[n][m];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int i0=0;
    int j0=0;
    while(i0<(n-i0) && j0<(m-j0))
    {
    j=j0;
    int k=2*(n-(2*i0))+2*(m-2-(2*j0));
    int *t;
    t=new int[k];
    int c=-1;
    for(i=i0;i<n-1-i0;i++)
    {
        t[(++c+r)%k]=a[i][j];
    }
    for(j=j0;j<m-1-j0;j++)
    {
        t[(++c+r)%k]=a[i][j];
    }
    j=m-(1+i0);
    for(i=n-(1+i0);i>=(1+i0);i--)
    {
        t[(++c+r)%k]=a[i][j];
    }
    i=i0;
    for(j=m-(1+j0);j>=(1+j0);j--)
    {
         t[(++c+r)%k]=a[i][j];
    }

    c=-1;
    for(i=i0;i<n-1-i0;i++)
    {
        a[i][j]=t[++c];
    }
    for(j=j0;j<m-1-j0;j++)
    {
        a[i][j]=t[++c];
    }
    j=m-(1+i0);
    for(i=n-(1+i0);i>=(1+i0);i--)
    {
        a[i][j]=t[++c];
    }
    i=i0;
    for(j=m-(1+j0);j>=(1+j0);j--)
    {
         a[i][j]=t[++c];
    }
        i0++;
        j0++;
        delete(t);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
