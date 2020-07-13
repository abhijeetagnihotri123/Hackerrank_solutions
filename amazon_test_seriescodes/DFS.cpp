#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>&,int,vector<bool>&);

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(graph,i,visited);
        }
    }
    return 0;
}
void dfs(vector<vector<int>>&graph,int s,vector<bool>&visited)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<graph[s].size();i++)
    {
        if(!visited[graph[s][i]])
        {   
            dfs(graph,graph[s][i],visited);
        }
    }
}