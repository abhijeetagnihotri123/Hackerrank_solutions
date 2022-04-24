#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void calculatez(string &s,vector<int>&z,int &n)
    {
        int l,r;
        l = r = 0;
        for(int k=1;k<n;k++)
        {
            if(k>l)
            {
                l = r = k;
                while(r<n && s[r] == s[r-l])
                {
                    r++;
                }
                z[k] = r-l;
                r--;
            }
            else
            {
                int k1 = k-l;
                if(z[k1] < r-k+1)
                {
                    z[k] = z[k1];
                }
                else
                {
                    l = k;
                    while(r<n && s[r] == s[r-l])
                    {
                        r++;
                    }
                    z[k] = r-l;
                    r--;
                }
            }
        }
    }
    vector <int> search(string pat, string txt)
    {
        vector<int>r;
        txt = pat+"$"+txt;
        int n = txt.length();
        vector<int>z(n,0);
        calculatez(txt,z,n);
        int m = pat.length();
        for(int i=0;i<n;i++)
        {
            if(z[i] == m)
            {
                r.push_back(i-m);
            }
        }
        return r;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}