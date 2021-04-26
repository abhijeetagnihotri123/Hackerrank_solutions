#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);
#define MAX_SIZE 100

class Solution
{
    public:
    void generate_parenthesis(int pos, int n, int open, int close,vector<string>&res)
    {
        static char str[MAX_SIZE];    
        if (close == n)
        {
            string s = string(str);
            res.push_back(s);
            return;
        }
        else
        {
            if (open > close)
            {
                str[pos] = ')';
                generate_parenthesis(pos + 1, n, open, close + 1,res);
            }
            if (open < n)
            {
                str[pos] = '(';
                generate_parenthesis(pos + 1, n,open + 1, close,res);
            }
        }
    }
    vector<string> AllParenthesis(int n) 
    {   
        vector<string>res;
        generate_parenthesis(0,n,0,0,res);
        return res;
    }
};

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 