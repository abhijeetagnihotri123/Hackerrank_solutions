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
int wordBreak(string A,vector<string>& B)
{   
    int n = A.length();
    vector<bool>dp(n+1,false);
    set<string>s;
    for(string x : B)
    {
        s.insert(x);
    }
    string word;
    dp[n] = true;
    for(int i=n-1;i>=0;i--)
    {
        word = "";
        for(int j=i;j<n;j++)
        {
            word += A[j];
            if(s.find(word) != s.end())
            {
                if(dp[j+1])
                {
                    dp[i] = true;
                }
            }
        }
    }
    return dp[0];
}