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
        m[a[i]]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<m[m[m[a[i]]]]<<endl;
    }
    return 0;
}

