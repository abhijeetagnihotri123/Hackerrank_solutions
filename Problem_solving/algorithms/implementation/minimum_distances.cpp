#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int>m;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    int min=1000;
    int d=0;
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        if(m[a[i]]>1)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[j]==a[i])
                {
                    d=j-i;
                    break;
                }
            }
            if(min>d)
            {
                min=d;            
            }
        }
        else 
        {
            c++;
        }
    }
    if(c==n-1)
    {
        min=-1;
    }
    cout<<min;
    return 0;
}
