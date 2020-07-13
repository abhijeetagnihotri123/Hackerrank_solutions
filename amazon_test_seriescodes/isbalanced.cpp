#include <bits/stdc++.h>
using namespace std;
bool ispar(string);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        cout<<ispar(str)<<endl;
    }
}
bool ispar(string x)
{
    stack<char>s;
    int n = x.length();
    for(int i=0;i<n;i++)
    {
        if(x[i] == '[')
        {
            s.push(x[i]);
        }
        else if(x[i] == '(')
        {
            s.push(x[i]);
        }
        else if(x[i] == '{')
        {
            s.push(x[i]);
        }
        else if(x[i] == ']')
        {
            if(s.size() == 0 || s.top() != '[')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else if(x[i] == ')')
        {
            if(s.size() == 0 || s.top() != '(')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else
        {
            if(s.size() == 0 || s.top() != '{')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}