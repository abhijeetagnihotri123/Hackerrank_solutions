#include <bits/stdc++.h>
using namespace std;

int SubsequenceLength(string&);

int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<SubsequenceLength(s)<<endl;
    }
    return 0;
}
void revert(map<char,bool>&m,int &c)
{
    c=0;
    for(char ch='a';ch<='z';ch++)
    {
        if(m[ch])
        {
            c++;
        }
        m[ch]=false;
    }
}
int SubsequenceLength(string &s)
{
    int i,j;
    i = j = 0;
    int n = s.length();
    int max_length = 0;//;-2147483648;
    int l;
    map<char,bool>m;
    for(char ch='a';ch<='z';ch++)
    {
        m[ch]=false;
    }
    while(i<n)
    {
        if(!m[s[i]])
        {
            m[s[i]]=true;
        }
        else
        {   
            revert(m,l);
            if(l>max_length)
            {
                max_length=l;
            }
        }
        i++;
    }
    return max_length;
}