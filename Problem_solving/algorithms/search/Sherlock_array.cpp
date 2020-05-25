#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        //int s=0;
        for(int i=0;i<n;i++)
        {   
            cin>>a[i];
        }
        int s=0;
        int i=0;
        int j=n-1;
        while(i!=j)
        {
            if(s>=0)
            {
                s=s-a[j];
                j--;
            }
            else
            {
                s=s+a[i];
                i++;
            }
        }
        if(s==0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
