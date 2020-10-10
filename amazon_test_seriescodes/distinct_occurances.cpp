#include <bits/stdc++.h>
using namespace std;
int subsequenceCount(string S, string T);

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		cout<<subsequenceCount(s,tt)<<endl;	
	}
    return 0;
}
int subsequenceCount(string S,string T)
{
    int n = S.length();
    int m = T.length();
    int DO[m+1][n+1];
    for(int i=1;i<=m;i++)
    {
        DO[i][0] = 0; 
    }
    for(int j=0;j<=n;j++)
    {
        DO[0][j] = 1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(T[i-1] != S[j-1])
            {
                DO[i][j] = DO[i][j-1];
            }
            else
            {
                DO[i][j] = DO[i][j-1] + DO[i-1][j-1];
            }
        }
    }
    return DO[m][n];
}