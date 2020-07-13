#include <iostream>
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    if(n<r)
    {
        cout<<0;
    }
    else
    {
        int c[r+1][n+1];
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0)
                {
                    c[i][j]=1;
                }
                else if(i==j)
                {
                    c[i][j]=1;
                }
                else if(j<i)
                {
                    c[i][j]=0;
                }   
                else
                {
                    c[i][j]=c[i-1][j-1]+c[i][j-1];   
                }
            }
        }
        cout<<c[r][n];
    }
    return 0;
}