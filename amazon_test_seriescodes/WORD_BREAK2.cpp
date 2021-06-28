#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,vector<string>>dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        if(dp.find(s) != dp.end())
        {
            return dp[s];
        }
        vector<string>result;
        for(string x : wordDict)
        {
            if(s.substr(0,x.length()) == x)
            {
                if(x.length() == s.length())
                {
                    result.push_back(x);
                }
                else
                {
                    vector<string>tmp = wordBreak(s.substr(x.length()),wordDict);
                    for(string y : tmp)
                    {
                        result.push_back(x + " "+y);
                    }
                }
            }
        }
        dp[s] = result;
        return result;
    }
};

int main()
{   
    int t;
    cin>>t;
    while(t--)
    {   
        string str;
        getline(cin,str);
        int n;
        cin>>n;
        vector<string>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        Solution obj;
        v = obj.wordBreak(str,v);
        for(string x : v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}