#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int>adj[],vector<int>visited,int curr)
{
    if(visited[curr] == 2)
    {
        return true;
    }
    visited[curr] = 1;
    bool FLAG = true;
    for(int i=0;i<adj[curr].size();++i)
    {
        if(visited[adj[curr][i]]==1)
            visited[adj[curr][i]] = 2;
        else
        {
            FLAG = isCyclicUtil(adj, visited, adj[curr][i]);
            if(FLAG==true)
                return true;
        }
    }
    return false;
}

bool isCyclic(vector<int>g[],int V)
{
    vector<int>visited(V,0);
    bool FLAG = false;
    for(int i=0;i<V;i++)
    {
        visited[i]=1;
        for(int j=0;j<g[i].size();j++)
        {
            FLAG = isCyclicUtil(g,visited,g[i][j]);
            if(FLAG == true)
            {
                return true;
            }
        }
        visited[i]=0;
    }
    return false;
}
int main()
{   
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}