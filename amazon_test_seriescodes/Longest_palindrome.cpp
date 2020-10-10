#include <bits/stdc++.h>
using namespace std;

string Longest_palindrome(string&);

int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        cout<<Longest_palindrome(s)<<endl;
    }
}
string Longest_palindrome(string &str)
{
    int n = str.size(); 
  
    bool table[n][n]; 
  
    memset(table, 0, sizeof(table)); 
  
    int maxLength = 1; 
  
    for (int i = 0; i < n; ++i) 
        table[i][i] = true; 
  
    int start = 0; 
    for (int i = 0; i < n - 1; ++i) { 
        if (str[i] == str[i + 1]) { 
            table[i][i + 1] = true; 
            start = i; 
            maxLength = 2; 
        } 
    } 
    for (int k = 3; k <= n; ++k) { 
        for (int i = 0; i < n - k + 1; ++i) { 
            int j = i + k - 1; 
  
            // checking for sub-string from ith index to 
            // jth index iff str[i+1] to str[j-1] is a 
            // palindrome 
            if (table[i + 1][j - 1] && str[i] == str[j]) { 
                table[i][j] = true; 
  
                if (k > maxLength) { 
                    start = i; 
                    maxLength = k; 
                } 
            } 
        } 
    } 
    string s = "";
    if(maxLength == 1)
    {
        s = str[0];
    }
    else if(maxLength == 2)
    {
        for(int i=0;i<n-1;i++)
        {
            if(str[i] == str[i+1])
            {
                s+=str[i];
                s+=str[i+1];
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