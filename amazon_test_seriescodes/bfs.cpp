#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>&);
int main()
{   
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v);
    for(int i=0;i<v;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(graph);
    return 0;
}
void bfs(vector<vector<int>>&graph)
{
     queue<int>q;
     int n = graph.size();
     bool visited[n] = {false};
     int s = 0;
     visited[s] = true;
     q.push(s);
     while(!q.empty())
     {
         int current = q.front();
         q.pop();
         cout<<current<<" ";
         for(int i=0;i<graph[current].size();i++)
         {
             if(!visited[graph[current][i]])
             {
                 visited[graph[current][i]]=true;
                 q.push(graph[current][i]);
             }
         }
     }
}