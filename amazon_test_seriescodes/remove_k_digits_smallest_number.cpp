#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string &num, int &k)
{
    stack<char>s;
    for(char c : num)
    {
        while(!s.empty() && s.top() > c && k>0)
        {
            s.pop();
            k--;
        }
        if(!s.empty() || c != '0')
        {
            s.push(c);
        }
    }
    num = "";
    while(!s.empty() && k--)
    {
        s.pop();
    }
    if(s.empty())
    {
        num = "0";
    }
    else
    {
        while(!s.empty())
        {
            num += s.top();
            s.pop();
        }
        reverse(num.begin(),num.end());
    }
    return num;
}
int main()
{   
    string n;
    int k;
    cin>>n>>k;
    cout<<removeKdigits(n,k);
    return 0;
}
