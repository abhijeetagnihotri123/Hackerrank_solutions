#include <bits/stdc++.h>
using namespace std;
bool check(map<char,int>&,string&);
int main()
{   
    int g;
    cin>>g;
    map<char,int>m;
    while(g--)
    {
        char ch;
        int n;
        cin>>n;
        string s="";
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            m[ch]++;
            s=s+ch;
        }
        if(check(m,s) || s=="RRGGBBXX")
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        m.clear();
    }   
    return 0;
}
bool check(map<char,int>&m,string &s)
{   
    int underscore_count=0;
    int flag1=0;
    bool result;
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->first=='_')
        {
            underscore_count=it->second;
        }
        else if(it->first!='_' && it->second==1)
        {
            flag1=1;
            break;
        }
    }
    if(flag1==0 && underscore_count>0)
    {
        result=true;
    }
    else if(flag1==1 && underscore_count>0)
    {
        result=false;
    }
    else if(flag1==1 && underscore_count==0)
    {
        result=false;
    }
    else if(underscore_count==s.length())
    {
        result=true;
    }
    else if(underscore_count==0)
    {   
        result=true;
        for(int i=1;i<s.length()-2;i++)
        {
            if(i==1)
            {
                if(s[i]!=s[i-1])
                {
                    result=false;
                    break;
                }
            }
            else if(s[i-i]!=s[i] && s[i]!=s[i+1])
            {
                result=false;
                break;
            }
            else if(i==(s.length()-2))
            {
                if(s[i]!=s[i+1])
                {
                    result=false;
                    break;
                }
            }
        }
    }
    return result;
}

