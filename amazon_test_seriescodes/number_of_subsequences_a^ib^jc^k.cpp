#include <bits/stdc++.h>
using namespace std;

int fun(string &s)
{
    int c_a = 0;
    int c_b = 0;
    int c_c = 0;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'a')
        {
            c_a = 1 + 2 * c_a;
        }
        else if(s[i] == 'b')
        {
            c_b = c_a + 2 * c_b;
        }
        else if(s[i] == 'c')
        {
            c_c = c_b + 2 * c_c;
        }
    }
    return c_c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<fun(s)<<endl;
    }
}