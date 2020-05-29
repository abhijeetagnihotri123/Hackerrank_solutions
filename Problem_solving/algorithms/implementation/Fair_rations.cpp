#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int B[n];
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
        s=s+B[i];
    }
    if(s%2==1)
    {
        cout<<"NO\n";
    }
    else
    {
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            if(B[i]%2==1)
            {
                B[i]=B[i]+1;
                B[i+1]=B[i+1]+1;
                c+=2;
            }
        }
        cout<<c;
    }
    return 0;
}

