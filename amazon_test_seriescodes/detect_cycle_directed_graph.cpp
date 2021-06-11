#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool iscyclic(vector<vector<int>>&g,int s,vector<bool>&v,vector<bool>&r)
    {
        if(v[s] == false)
        {
            v[s] = true;
            r[s] = true;
            for(int x : g[s])
            {
                if(!v[x] && iscyclic(g,x,v,r))
                {
                    return true;
                }
                else if(r[x])
                {
                    return true;
                }
            }
        }
        r[s] = false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    vector<vector<int>>g(N);
	    for(pair<int,int>x : p)
	    {
	        int u,v;
	        u = x.second;
	        v = x.first;
	        g[u].push_back(v);
	    }
	    bool flag = true;
	    vector<bool>v(N,false);
	    vector<bool>r(N,false);
	    for(int i=0;i<N;i++)
	    {
	        if(iscyclic(g,i,v,r))
	        {
	            flag = false;
	            break;
	        }
	    }
	    return flag;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}