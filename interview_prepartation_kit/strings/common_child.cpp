#include <bits/stdc++.h>
using namespace std;
int main()
{   
    string s1,s2,str1,str2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    int L[2][m+1];
    bool bi;
    for(int i=0;i<=n;i++)
    {
        bi=i&1;
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                L[bi][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                L[bi][j]=L[1-bi][j-1]+1;
            }
            else
            {
                L[bi][j]=max(L[1-bi][j],L[bi][j-1]);
            }
        }
    }
    cout<<L[bi][m];
    
    return 0;
}
