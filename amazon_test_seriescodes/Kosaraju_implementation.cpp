#include <bits/stdc++.h>
using namespace std;

int kosaraju(int,vector<int>[]);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int m,n;
        vector<int>adj[a];
        for(int i=0;i<b;i++)
        {
            cin>>m>>n;
            adj[m].push_back(n);
        }
        cout<<kosaraju(a,adj);
    }
}
void DFS_UTIL_STAMP(vector<int>adj[],int v,vector<bool>&visited,stack<int>&s)
{
    visited[v] = true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {
            DFS_UTIL_STAMP(adj,adj[v][i],visited,s);
        }
    }
    s.push(v);
}
void DFS_UTIL(vector<vector<int>>&graph,int v,vector<bool>&visited)
{
    visited[v] = true;
    for(int i=0;i<graph[v].size();i++)
    {
        if(!visited[graph[v][i]])
        {
            DFS_UTIL(graph,graph[v][i],visited);
        }
    }
}
void invert_graph(vector<int>adj[],vector<vector<int>>&adj_transpose,int v,vector<bool>&visited)
{
    for(int i=0;i<v;i++)
    {   
        visited[i]=false;
        for(int j=0;j<adj[i].size();j++)
        {
            adj_transpose[adj[i][j]].push_back(i);
        }
    }
}
int kosaraju(int V,vector<int>adj[])
{   
    vector<vector<int>>adj_transpose(V);
    stack<int>s;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            DFS_UTIL_STAMP(adj,i,visited,s);
        }
    }
    invert_graph(adj,adj_transpose,V,visited);
    int c = 0;
    int ele;
    while(!s.empty())
    {
        ele = s.top();
        if(!visited[ele])
        {
            DFS_UTIL(adj_transpose,ele,visited);
            c++;
        }
        s.pop();
    }
    return c;
}