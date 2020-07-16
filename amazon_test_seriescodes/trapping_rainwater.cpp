#include <iostream>
#include <stack>
#include <queue>
// very very important
using namespace std;
int min(int a,int b)
{
    return a<=b ? a:b;
}
int max(int a,int b)
{
    return a>=b?a:b;
}
int n_squared(int a[],int n)
{
    int total_water = 0;
    int max1,max2;
    for(int i=1;i<n-1;i++)
    {
        max1=a[i-1];
        max2=a[i];
        for(int j=0;j<=i;j++)
        {
            if(max1 < a[j])
            {
                max1=a[j];
            }
        }
        for(int j=i;j<n;j++)
        {
            if(max2 < a[j])
            {
                max2=a[j];
            }
        }
        int water = min(max1,max2);
        total_water += water-a[i];
    }
    return total_water;
}
int n_space(int a[],int n)
{   
    int total_water = 0;
    int *lm,*rm;
    lm = new int[n];
    rm = new int[n];
    lm[0]=a[0];
    rm[n-1]=a[n-1];
    for(int i=1;i<n;i++)
    {
        lm[i]=max(lm[i-1],a[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        rm[i]=max(rm[i+1],a[i]);
    }
    for(int i=0;i<n;i++)
    {
        int water = min(lm[i],rm[i]);
        total_water += water-a[i];
    }
    return total_water;
}
int O1_space(int a[],int n)
{
    return 0;
}
int main()
{   
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<n_squared(a,n)<<" "<<n_space(a,n);
    return 0;
}