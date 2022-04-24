#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool check(int i,int j,int &n)
    {
        if(i<0 || i>=n || j<0 || j>=n)
        {
            return false;
        }
        return true;
    }
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>>d(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        d[0][0] = grid[0][0];
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int cost = 0;
        pq.push(make_pair(grid[0][0],make_pair(0,0)));
        while(!pq.empty())
        {
            pair<int,pair<int,int>>p = pq.top();
            pq.pop();
            cost = cost+p.first;
            int i = p.second.first;
            int j = p.second.second;
            if(i == n-1 && j == n-1)
            {
                break;
            }
            for(int k=0;k<4;k++)
            {
                int idx = i+dx[k];
                int idy = j+dy[k];
                if(check(idx,idy,n))
                {   
                    if(d[idx][idy] >= (d[i][j]+grid[idx][idy]))
                    {
                        d[idx][idy] = d[i][j]+grid[idx][idy];
                        pq.push(make_pair(d[idx][idy],make_pair(idx,idy)));
                    }
                }
            }
        }
        return d[n-1][n-1];
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
} 