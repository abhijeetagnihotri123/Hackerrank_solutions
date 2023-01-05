#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int longestCommonSubstr (string X, string Y, int n, int m)
    {
        int C[n+1][m+1];
        int longest_length = 0;
        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= m ; j++)
            {
                if(i == 0 || j == 0)
                {
                    C[i][j] = 0;
                }
                else if(X[i-1] == Y[j-1])
                {
                    C[i][j] = 1 + C[i-1][j-1];
                    longest_length = max(longest_length,C[i][j]);
                }
                else
                {
                    C[i][j] = 0;
                }
            }
        }
        return longest_length;
    }
    


};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}