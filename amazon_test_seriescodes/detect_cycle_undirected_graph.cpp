#include <bits/stdc++.h>
using namespace std;


int root(int i,vector<int>&parent)
{
    while(parent[i] != i)
    {
        parent[i] = parent[parent[i]];
        i = parent;
    }
    return i;
}
bool find(int A,int B,vector<int>&parent)
{
    if(root(A,parent) == root(B,parent))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Union(int A,int B,vector<int>&parent)
{
    if(find(A,B,parent))
    {
        return ;
    }
    else
    {
        int root_A = root(A,parent);
        int root_B = root(B,parent);
        parent[root_B] = parent[root_A];
        root_B = root(root_B,parent);   
    }
}
void BFS(vector<int>g[],int s,vector<bool>&visited,bool &flag)
{
    
}
bool isCyclic(vector<int>g[],int V)
{
    vector<int>parent(V,-1);
    bool flag = false;
    int u,v;
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<V;i++)
    {
        u = g[i][0];
        for(int j=0;j<g[i].size();j++)
        {
            v = g[i][j];
            Union(u,v,parent);
        }
    }
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && !flag)
        {
            BFS(g,i,visited,flag)
        }
    }
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