#include <bits/stdc++.h>
using namespace std;

int findMother(int,vector<int>[]);
int main()
{   
    int t,a,b,m,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        vector<int>adj[a];
        for(int i=0;i<b;i++)
        {
            cin>>m>>n;
            adj[m].push_back(n);
        }
        cout<<findMother(a,adj)<<endl;
    }
    return 0;
}
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