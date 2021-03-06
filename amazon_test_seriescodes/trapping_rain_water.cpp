#include <iostream>
using namespace std;
int max_min(int &a,int &b,bool mode)
{
    return mode?(a>=b?a:b):(a<=b?a:b);
}
int trappingWater(int[],int);
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<trappingWater(a,n);
    }
    return 0;
}
int trappingWater(int a[],int n)
{
    int *lm,*rm,total_water,water;
    total_water = 0;
    lm = new int[n];
    rm = new int[n];
    lm[0] = a[0];
    rm[n-1] = a[n-1];
    for(int i=1;i<n;i++)
    {
        lm[i] = max_min(lm[i-1],a[i],true);
        rm[n-i-1] = max_min(rm[n-i],a[n-i-1],true);
    }
    for(int i=0;i<n;i++)
    {
        water = max_min(lm[i],rm[i],false);
        total_water += water-a[i];
    }
    return total_water;
}