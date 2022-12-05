#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int palindromicPartition(string s)
    {
        int n = s.length();
		bool P[n][n];
		int C[n];
		int i,j,L;
		for(i=0;i<n;i++)
		{
			P[i][i] = true;
		}
        for(L = 2; L <= n; L++)
		{
			for(i = 0; i < n - L + 1 ; i++)
			{
				j = i + L - 1;
				if(L == 2)
				{
					P[i][j] = (s[i] == s[j]);
				}
				else
				{
					P[i][j] = (s[i] == s[j]) && P[i+1][j-1];
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(P[0][i])
			{
				C[i] = 0;
			}
			else
			{
				C[i] = INT_MAX;
				for(int j=0;j<i;j++)
				{
					if(P[j+1][i] && (1 + C[j] < C[i]))
					{
						C[i] = 1 + C[j];
					}
				}
			}
		}
		return C[n-1];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
