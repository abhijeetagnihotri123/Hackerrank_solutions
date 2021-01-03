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
int isValidUtil(string &s)
{   
    if(s.length() == 0 || s.length()>3)
    {
        return 0;
    }
    else if(s.length() == 1 && s[0] == '0')
    {
        return 1;
    }
    else
    {
        int number = 0;
        for(int i=0;i<s.length();i++)
        {
            int a = int(s[i]-'0');
            number = number * 10 + a;
        }
        if(number >0 && number <=255)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int isValid(char *ip)
{
    int n = strlen(ip);
    int num_dots = 0;
    for(int i=0;i<n;i++)
    {
        if(ip[i] == '.')
        {
            num_dots++;
        }
    }
    if(num_dots!=3)
    {
        return 0;
    }
    ip[n+1]='.';
    n = n+1;
    string s = "";
    int i=0;
    for(;i<n;i++)
    {
        if(ip[i] == '.' || i == n-1)
        {     
            int aux = isValidUtil(s);
            result = result & aux;
            s="";
        }
        else
        {
            s += ip[i];
        }
    }
    return result;
}