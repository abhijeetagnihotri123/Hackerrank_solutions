#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // s is the given string
    int SubsequenceLength (string s) 
    {
        int max_length = 0;
    int n = s.length();
    if(n == 0 || n == 1)
    {
        max_length = n;
    }
    else if(n == 2)
    {
        max_length = s[0]==s[1]?1:2;
    }
    else
    {
        vector<int>m(26,-1);
        int i,j,n,length;
        n = s.length();
        i = 0;
        j = i+1;
        m[int(s[0]-'a')] = 0;
        while(i<n && j<n)
        {   
            if(m[int(s[j]-'a')] != -1 && m[int(s[j]-'a')]>=i && m[int(s[j]-'a')] < j)
            {
                i = m[int(s[j]-'a')]+1;
            }
            length = j-i+1;
            if(length > max_length)
            {
                max_length = length;
            }
            m[int(s[j]-'a')] = j;
            j++;
        }
    }
    return max_length;
    }
};

int main()
{
    int t;
    cin>>t;
    cin>>ws;
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution obj;
        cout<<obj.SubsequenceLength(str)<<"\n";
    }
    return 0;
}