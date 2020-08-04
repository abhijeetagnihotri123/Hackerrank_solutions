#include <bits/stdc++.h>
using namespace std;
int VersionCompare(string v1, string v2)
{   
    v1+='.';
    v2+='.';
    int n = v1.length();
    int m = v2.length();
    //vector<int>version1;
    //vector<int>version2;
    int c1,c2;
    c1 = c2 = -1;
    string s = "";
    int sum[2],result;
    sum[0] = sum[1] = 0;
    for(int i=0;i<n;i++)
    {
        if(v1[i] == '.')
        {   
            int c = stoi(s);
            s="";
            sum[0] = sum[0]*10+c;
            c1++;
        }
        else
        {
            s+=v1[i];
        }
    }
    for(int i=0;i<m;i++)
    {
        if(v2[i] == '.')
        {   
            int c = stoi(s);
            s="";
            sum[1] = sum[1]*10+c;
            c2++;
        }
        else
        {
            s+=v2[i];
        }
    }
    if(sum[0] == sum[1] && c1 == c2)
    {   
        result = 0;
    }
    else
    {
        int d = c1>c2?(c1-c2):(c2-c1);
        int index = c1>c2?1:0;
        while(d--)
        {
            sum[index] *= 10;
        }
        result = sum[0]>sum[1]?1:-1;
    }
    return result;
}
int main()
{   
    int t;
    cin>>t;
    string s1,s2;
    while(t--)
    {
        cin>>s1>>s2;
        cout<<VersionCompare(s1,s2)<<endl;
    }
    return 0;
}