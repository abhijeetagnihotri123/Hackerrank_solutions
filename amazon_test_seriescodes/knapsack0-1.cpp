#include <iostream>
using namespace std;
int max(int a,int b)
{
    return a>=b ? a:b;
}
int knapSack_recursion(int W,int wt[],int val[],int n)
{
    if(W == 0 || n == 0)
    {
        return 0;
    }
    if(wt[n-1] > W)
    {
        return knapSack_recursion(W,wt,val,n-1);
    }
    else
    {   
        int val1 = val[n-1] + knapSack_recursion(W-wt[n-1],wt,val,n-1);
        int val2 = knapSack_recursion(W,wt,val,n-1);
        return max(val1,val2);
    }
}
int knapSack_dynamic(int W,int wt[],int val[],int n)
{
    int C[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                C[i][j]=0;
            }
            else if(wt[i-1] <= j)
            {
                C[i][j]=max(val[i-1]+C[i-1][j-wt[i-1]],C[i-1][j]);
            }
            else
            {
                C[i][j]=C[i-1][j];
            }
        }
    }
    return C[n][W];
}
int main()
{   
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(wt)/sizeof(int);
    cout<<knapSack_dynamic(W,wt,val,n);
    return 0;
}