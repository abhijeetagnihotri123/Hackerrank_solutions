#include <bits/stdc++.h>
using namespace std;
vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}
string encodePattern(string pattern)
{
    unordered_map<char,int>m;
    int i = 0;
    string res = "";
    for(char c : pattern)
    {
        if(m.find(c) == m.end())
        {
            m[c]=i++;
        }
        res += to_string(m[c]);
    }
    return res;
}
vector<string> findMatchedWords(vector<string>dict,string pattern)
{
    vector<string>res;
    string p1 = encodePattern(pattern);
    string p2;
    for(string x : dict)
    {
        p2 = encodePattern(x);
        if(p1 == p2)
        {
            res.push_back(x);
        }
    }
    return res;
}

