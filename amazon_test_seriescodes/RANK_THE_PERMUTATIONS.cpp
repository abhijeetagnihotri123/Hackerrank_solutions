#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    long long findRank(string str) 
    {
        long long f[19];
        f[0] = 1;
        f[1] = 1;
        for(int i=2;i<=18;i++)
        {
            f[i] = f[i-1]*i;
        }
        vector<bool>visited(26,false);
        for(char &c : str)
        {
            int index = int(c-'a');
            visited[index] = true;
        }
        int num_smaller;
        long long rank = 1;
        int n = str.length();
        for(int i=0;i<n;i++)
        {   
            int index = int(str[i]-'a');
            num_smaller = 0;
            for(int j=0;j<26;j++)
            {
                if(j == index)
                {
                    break;
                }
                if(visited[j])
                {
                    num_smaller++;
                }
            }
            visited[index] = false;
            rank += num_smaller*f[n-1-i];
        }
        return rank;
    }
};

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}