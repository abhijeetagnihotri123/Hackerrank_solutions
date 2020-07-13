#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>&graph,int s,int e)
{
    vector<bool>visited(graph.size(),false);
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i=0;i<graph[current].size();i++)
        {
            int v = graph[current][i];
            if(!visited[v] && v == e && current == s)
            {
                // do nothing
            }
            else if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
    return !visited[e];
}
int main()
{   
    int n,m,s,e;
    cin>>n>>m;
    vector<vector<int>>graph(n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>s>>e;
    cout<<bfs(graph,s,e);
    return 0;
}