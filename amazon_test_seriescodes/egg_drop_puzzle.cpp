#include <iostream>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int eggDroprecursive(int,int);
int eggDropDynamic(int,int);
int main()
{   
    int T,n,k;
    cin>>T;
    while(T--)    
    {
        cin>>n>>k;
        cout<<eggDropDynamic(n,k)<<endl;
    }
    return 0;
}
int eggDroprecursive(int n,int k)
{
    if(k == 1 || k == 0)
    {
        return k;
    }
    if(n == 1)
    {
        return k;
    }
    int res;
    int Min = 2147483647;
    for(int x=1;x<=k;x++)
    {
        res = max(eggDroprecursive(n-1,x-1),eggDroprecursive(n,k-x));
        if(res < Min)
        {
            Min = res;
        }
    }
    return Min+1;
}
int eggDropDynamic(int n,int k)
{
    int C[n+1][k+1];
    int i,j,res;
    for(int i=0;i<=n;i++)
    {
        C[i][0]=0;
        C[i][1]=1;
    }
    for(int j=1;j<=k;j++)
    {
        C[1][j]=j;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            C[i][j]=2147483647;
            for(int x=1;x<=j;x++)
            {
                int h1 = C[i-1][x-1];
                int h2 = C[i][j-x];
                res = max(h1,h2)+1;
                if(res < C[i][j])
                {
                    C[i][j]=res;
                }
            }
        }
    }
    return C[n][k];
}