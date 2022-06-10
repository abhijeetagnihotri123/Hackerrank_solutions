#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    /*
    1st Method did not understand well
    void DFS_UTIL(vector<int>adj[],int v,vector<bool>&visited)
    {
        visited[v] = true;
        for(int i=0;i<adj[v].size();i++)
        {
            if(!visited[adj[v][i]])
            {
                DFS_UTIL(adj,adj[v][i],visited);
            }
        }
    }
    int findMother(int V,vector<int>adj[])
    {
        vector<bool>visited(V,false);
        int last_vertex = 0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS_UTIL(adj,i,visited);
                last_vertex = i;
            }
        }
        fill(visited.begin(),visited.end(),false);
        DFS_UTIL(adj,last_vertex,visited);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                return -1;
            }
        }
        return last_vertex;
    }
    */
    void DFS(int v,vector<int>adj[],stack<int>&s,vector<bool>&visited)
    {
        visited[v] = true;
        for(int &x : adj[v])
        {
            if(!visited[x])
            {
                DFS(x,adj,s,visited);
            }
        }
        s.push(v);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
        stack<int>s;
        vector<bool>v(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(i,adj,s,visited);
            }
        }
        fill(visited.begin(),visited.end(),false);
        int t = s.top();
        DFS(t,adj,s,visited);
        for(bool &x : visited)
        {
            if(!x)
            {
                return -1;
            }
        }
        return t;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}