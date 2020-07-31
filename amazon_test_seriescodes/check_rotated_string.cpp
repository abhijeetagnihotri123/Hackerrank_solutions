#include <bits/stdc++.h>
using namespace std;

bool isRotated(string &s1,string &s2)
{
    int n = s1.length();
    int m = s2.length();
    if( n == 1)
    {
        return s1[0] == s2[0];
    }
    else if(n == 2)
    {
        return (s1 == s2);
    }
    else if(n != m)
    {
        return false;
    }
    else
    {   
        int c1 = 0;
        int c2 = 0;
        int i = 2;
        while(i<n && s1[i] == s2[i-2])
        {
            i++;
            c1++;
        }
        if(s1[0] == s2[n-2] && s1[1] == s2[n-1])
        {
            c1 = c1+2;
        }
        i = 2;
        while(i<n && s2[i] == s1[i-2])
        {
            i++;
            c2++;
        }
        if(s2[0] == s1[n-2] && s2[1] == s1[n-1])
        {
            c2 = c2+2;
        }
        return (c1 == n || c2 == n);
}
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<<isRotated(s1,s2)<<endl;
    }
    return 0;
}