#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{   
    string str="";
    stack<string>text;
    int Q,x,k;
    cin>>Q;
    while(Q--)
    {
        cin>>x;
        if(x==1)
        {   
            string st;
            cin>>st;
            text.push(str);
            str+=st;
        }
        else if(x==2)
        {
            cin>>k;
            text.push(str);
            str.erase(str.size()-k);
        }
        else if(x==3)
        {
            cin>>k;
            cout<<str[k-1]<<endl;
        }
        else
        {
            str=text.top();
            text.pop();
        }
        
    }
    return 0;
}
