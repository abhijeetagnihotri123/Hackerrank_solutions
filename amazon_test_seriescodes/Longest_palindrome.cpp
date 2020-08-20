#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string);

// Your code will be pasted here

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}

string longestPalindrome(string s)
{
    int n = s.length();
    int maxLength = 1;
    int start;
    bool dp[n][n];
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        {   
            dp[i][j] = false;
            dp[i][i] = true;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(s[i] == s[i+1])
        {   start = i;
            dp[i][i+1] = true;
            maxLenghth = 2;
        }
        else
        {
            dp[i][i+1] = false;
        }
        
    }
    for(int k=3;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j = i+k-1;
            if(dp[i+1][j-1] && s[i] == s[j])
            {
                dp[i][j] = true;
                if(maxLength < k)
                {
                    maxLength = k;
                    start = i;
                }
            }
        }
    }
    string str = "";
    if(maxLength == 1)
    {
        str = s[0];
    }
    else if(maxLength == 2)
    {
        for(int i=0;i<n-1;i++)
        {
            if(str[i] == str[i+1])
            {
                str+=s[i];
                str+=s[i+1];
                break;
            }
        }
    }
    else
    {
        for(int i=start;i<start+maxLength;i++)
        {   
            s+=str[i];
        }
    }
    return s;
}