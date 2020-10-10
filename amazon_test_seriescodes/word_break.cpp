#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
    return 0;
}
int wordBreak(string A,vector<string> &B)
{
    set<string>s;
    int n = A.size();
    for(int i=0;i<B.size();i++)
    {
        s.insert(B[i]);
    }
    vector<bool>dp(A.size()+1,false);
    dp[0] = true;
    for(int len=1;len<=n;len++)
    {
        if(!dp[len])
        {
            string str = A.substr(0,len);
            if(s.find(str) != s.end())
            {
                dp[len] = true;
            }
        }
        if(dp[len] && len == n)
        {
            return true;
            for(int j = len+1;j<=n;j++)
            {
                if(!dp[j])
                {
                    string str = A.substr(len,j-len);
                    if(s.find(str) != s.end())
                        {dp[j] = true;}
                }
                if(dp[j] && j==n)
                {
                    return true;
                }
            }
        }
    }
    return dp[n];
}