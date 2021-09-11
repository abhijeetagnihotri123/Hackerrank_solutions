#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int l, int p, int q, int r)
    {int dp[l + 1];
  
    // All values with -1
    memset(dp, -1, sizeof(dp));
  
    // if length of rod is 0 then total cuts will be 0
    // so, initialize the dp[0] with 0
    dp[0] = 0;
  
    for (int i = 0; i <= l; i++) {
  
        // if certain length is not possible
        if (dp[i] == -1)
            continue;
  
        // if a segment of p is possible
        if (i + p <= l)
            dp[i + p] = max(dp[i + p], dp[i] + 1);
  
        // if a segment of q is possible
        if (i + q <= l)
            dp[i + q] = max(dp[i + q], dp[i] + 1);
  
        // if a segment of r is possible
        if (i + r <= l)
            dp[i + r] = max(dp[i + r], dp[i] + 1);
    }
    // if no segment can be cut then return 0
    if (dp[l] == -1) {
        dp[l] = 0;
    }
    // return value corresponding to length l
    return dp[l];
    }
};

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
