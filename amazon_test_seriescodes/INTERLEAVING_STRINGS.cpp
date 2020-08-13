#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string&,string&,string&);
int main()
{   
    int T;
    cin>>T;
    while(T--)
    {
        string A,B,C;
        cin>>A>>B>>C;
        cout<<isInterleave(A,B,C)<<endl;
    }
    return 0;
}
bool isInterleave(string &A,string &B,string &C)
{
    int n = A.length();
    int m = B.length();
    int L = C.length();
    if((n+m)!=L)
    {
        return false;
    }
    else
    {   
        bool result[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0)
                {
                    result[i][j]=true;
                }
                else if(i==0)
                {
                    result[i][j]=result[i][j-1];
                }
                else if(j==0)
                {
                    result[i][j]=result[i-1][j];
                }
                else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1])
                {
                    result[i][j]=result[i-1][j];
                }
                else if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1])
                {
                    result[i][j]=result[i][j-1];
                }
                else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1])
                {
                    result[i][j]=(result[i-1][j] || result[i][j-1]);
                }
            }
        }
        return result[n][m];
    }
}