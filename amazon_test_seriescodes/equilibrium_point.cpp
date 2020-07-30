#include <iostream>
using namespace std;

int equilibrium_point(int a[],int n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return -1;
    }
    else if(n == 3)
    {
        if(a[0] == a[2])
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int b[n];
        b[0] = a[0];
        for(int i=1;i<n;i++)
        {
            b[i] = b[i-1]+a[i];
        }
        int index = -1;
        int total = b[n-1];
        for(int i=1;i<n-1;i++)
        {
            int l = b[i] - a[i];
            int r = total - b[i];
            if(l == r)
            {
                index = i+1;
                break;
            }
        }
        return index;
    }
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
    cout<<equilibrium_point(a,n);
    return 0;
}