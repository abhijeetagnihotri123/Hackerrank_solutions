#include <bits/stdc++.h>
using namespace std;
int romanToInt(string);
int main()
{
    string roman_number;
    cin>>roman_number;
    cout<<romanToInt(roman_number);
    return 0;
}

int romanToInt(string s)
{
    int n = s.length();
    char c;
    int i=n-1;
    int result = 0;
    for(;i>=0;i--)
    {
        c = s[i];
        switch (c)
        {
        case 'I':
            result += 1*(result>=5?-1:1);
            break;
        case 'V':
            result += 5;
            break;
        case 'X':
            result += 10*(result>=50?-1:1);
            break;
        case 'L':
            result += 50;
            break;
        case 'C':
            result += 100 * (result>=500?-1:1);
            break;
        case 'D':
            result += 500;
            break;
        case 'M':
            result += 1000;
            break;
        default:
            //do nothing
            break;
        }
    }
    return result;
}