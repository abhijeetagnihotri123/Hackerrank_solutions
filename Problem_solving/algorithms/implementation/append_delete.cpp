#include <bits/stdc++.h>
using namespace std;
int main()
{   
    string s,t;
    cin>>s;
    cin>>t;
    int k;
    cin>>k;
    int commonlength=0;
    for(int i=0;i<t.length();i++)
    {
        if(s[i]==t[i])
        {
            commonlength++;
        }
        else
        {
            break;
        }
    }
    if((s.length()+t.length()-2*commonlength)>k)
    {
        cout<<"No\n";
    }
    else if((s.length()+t.length())<k)
    {
        cout<<"Yes\n";
    }
    else if((s.length()+t.length())%2==k%2)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    
    return 0;
}

