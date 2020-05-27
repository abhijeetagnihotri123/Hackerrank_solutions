#include<iostream>
#include<map>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int a[n];
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]=0;
    }
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    int pos;
    for(int i=0;i<n;i++)
    {
        if(m[a[i]]==1)
        {
            pos=i;
            break;
        }
    }
    cout<<a[pos];
    return 0;
}

