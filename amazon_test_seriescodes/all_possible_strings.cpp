#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        cout << isValid(s) << endl;
    }
    return 0;
}
int isValid(char *ip)
{
    int n = strlen(ip);
    if(n<7)
    {
        return 0;
    }
    else
    {
        int i=0;
        string str = "";
        vector<string>v;
        while(i<n)
        {
            if(ip[i]=='.')
            {
                if(str.length()>0)
                {
                    v.push_back(str);
                }
                str="";
            }
            else
            {
                str+=ip[i];
            }
            i++;    
        }
        if(str.length()>0)
        {
            v.push_back(str);
        }
        for(string x : v)
        {
            cout<<x<<endl;
        }
    }
    return 1;
}