#include <iostream>
using namespace std;
int lcs(string,string,int,int);
int lcs_dynamic(string,string);
int max(int,int);
int main()
{   

    string a,b;
    cin>>a>>b;
    int i=a.length();
    int j=b.length();
    cout<<lcs_dynamic(a,b);
    return 0;
}
int lcs(string X,string Y,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }   
    if(X[n-1] == Y[m-1])
    {
        return 1+lcs(X,Y,n-1,m-1);
    }
    else
    {
        return max(lcs(X,Y,n-1,m),lcs(X,Y,n,m-1));
    }
}
int max(int a,int b)
{
    return a>b?a:b;
}
int lcs_dynamic(string x,string y)
{
    int n=x.length();
    int m=y.length();
    int c[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                c[i][j]=0;
            }
            else if(x[i-1] == y[j-1])
            {
                c[i][j]=1+c[i-1][j-1];
            }
            else
            {
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    return c[n][m];
}