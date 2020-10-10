#include <bits/stdc++.h>
using namespace std;

bool issubsequence(string&,string&);
string largest_word(string&,vector<string>&);
int main()
{
    int T,N;
    cin>>T;
    //string s1 = "monkey";
    //string s2 = "abpcplea";
    while(T--)
    {
        cin>>N;
        vector<string>v(N,"");
        string s;
        for(int i=0;i<N;i++)
        {
            cin>>v[i];
        }
        cin>>s;
        cout<<largest_word(s,v)<<endl;
    }
}
bool issubsequence(string &s1,string &s2)
{
    int n = s1.length();
    int m = s2.length();
    int j = 0;
    int i = 0;
    while(i<n && j<m)
    {
        if(s1[i] == s2[j])
        {
            j++;
        }
        i++;
    }
    return j==m;
}
string largest_word(string &s,vector<string>&v)
{
    int n,m;
    n = s.length();
    string result = "";
    int lenght = 0;
    for(int i=0;i<v.size();i++)
    {
        m = v[i].length();
        if(issubsequence(s,v[i]) && lenght < v[i].length())
        {
            lenght = v[i].length();
            result = v[i];
        }
    }
    return result;
}
