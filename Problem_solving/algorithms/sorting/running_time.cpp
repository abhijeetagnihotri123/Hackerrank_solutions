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
    int c=0;
    for(int i=1;i<n;i++)
    {
        int h=i;
        int value=a[i];
        while(h>0&&a[h-1]>value)
        {
            a[h]=a[h-1];
            h=h-1;
            c++;
        }
        a[h]=value;
    }
    cout<<c;
    return 0;
}

