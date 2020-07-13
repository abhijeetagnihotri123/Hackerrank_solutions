#include <iostream>
using namespace std;
int max(int,int);
int main()
{   
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    int r[n+1]={-1};
    r[0]=0;
    for(int i=1;i<=n;i++)
    {
        int q = -2147483647;
        if(i>=x)
        {
            q = max(q,x+r[i-x]);
        }
        if(i>=y)
        {
            q = max(q,y+r[i-y]);
        }
        if(i>=z)
        {
            q = max(q,z+r[i-z]);
        }
        r[i]=q;
    }
    cout<<r[n];
    return 0;
}
int max(int a,int b)
{
    return a>=b ? a:b;
}