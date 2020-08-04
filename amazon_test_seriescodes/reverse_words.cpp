#include <bits/stdc++.h>

using namespace std;

void reverseWords(char *s)
{
    int n = strlen(s);
    string str = "";
    vector<string>strings;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '.')
        {
            strings.push_back(str);
            str = "";
        }
        else
        {
            str+=s[i];
        }
    }
    strings.push_back(str);
    str = "";
    for(int i=strings.size()-1;i>=1;i--)
    {
        str+=strings[i];
        str+='.';
    }
    str+=strings[0];
    cout<<str;
}
int main()
{   
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
    return 0;
}