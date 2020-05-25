#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                cout<<i<<" ";
            }
        }
        else if(n%(2*k)==0)
        {
            int temp=k;
            for(int i=1;i<=n;i++)
            {
                cout<<i+temp<<" ";
                if(i%k==0)
                {
                    temp=-temp;
                }
            }
        }
        else{cout<<-1;}
        cout<<endl;
    }
    return 0;
}

