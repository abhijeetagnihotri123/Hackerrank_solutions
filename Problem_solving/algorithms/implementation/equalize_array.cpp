#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m=0;
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j])
            {
                    c++;
            }
        }
        if(c>m)
        {
            m=c;
        }
    }
    cout<<(n-m);
    return 0;
}
