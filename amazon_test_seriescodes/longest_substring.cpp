#include <bits/stdc++.h>
using namespace std;

int SubsequenceLength(string s);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<SubsequenceLength(str)<<endl;
    }
}
int SubsequenceLength(string s)
{
    int i,j,l;
    i = j = 0;
    int n = s.length();
    map<char,bool>m;
    while(i<n-1)
    {   
        j = i;
        if(!m[])
    }
}