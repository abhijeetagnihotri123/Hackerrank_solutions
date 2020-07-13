#include <bits/stdc++.h>
using namespace std;
int main()
{   
    string str;
    cin>>str;
    int n = str.length();
    stack<int>s;
    int a,b,x;
    for(int i=0;i<n;i++)
    {
        if(str[i] == '+')
        {
            b  = s.top();
            s.pop();
            a = s.top();
            s.pop();
            x = a + b; 
            s.push(x); 
        }
        else if(str[i] == '-')
        {
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            x = a - b;
            s.push(x);
        }
        else if(str[i] == '*')
        {
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            x = a * b;
            s.push(x);
        }
        else if(str[i] == '/')
        {
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            x = a / b;
            s.push(x);
        }
        else
        {
            x = int(str[i]-48);
            s.push(x);
        }
    }
    cout<<s.top();
    return 0;
}