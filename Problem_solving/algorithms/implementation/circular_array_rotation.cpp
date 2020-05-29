#include<iostream>
using namespace std;
int main()
{
    int n,k,q;
    int Q;
    cin>>n>>k>>q;
    int a[n];
    int t[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        t[i]=0;
    }
    for(int i=0;i<n;i++)
    {
            t[(i+k)%n]=a[i];
    }
    for(int i=0;i<q;i++)
    {
        cin>>Q;
        cout<<t[Q]<<endl;
    }
    return 0;
}
