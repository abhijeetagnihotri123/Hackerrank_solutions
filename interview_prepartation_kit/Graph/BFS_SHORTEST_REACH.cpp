#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int> >,int,int);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,s;
        cin>>n>>m;
        vector<vector<int> >g(n+1);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin>>s;
        BFS(g,s,n);
        cout<<endl;
    }
    return 0;
}
void BFS(vector<vector<int> >graph,int s,int n)
{
    map<int,bool> visited;
    int l=0;
    map<int,int>distance;
    for(int i=1;i<=n;i++)
    {
        distance[i]=-1;
    }
    queue<int>Q;
    Q.push(s);
    visited[s]=true;
    distance[s]=0;
    while(!Q.empty())
    {
        int current=Q.front();
        Q.pop();
        for(int i=0;i<graph[current].size();i++)
        {
            if(!visited[graph[current][i]])
            {
                visited[graph[current][i]]=true;
                distance[graph[current][i]]=distance[current]+1;
                Q.push(graph[current][i]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(distance[i]==-1)
        {
            cout<<-1<<" ";
        }
        else if(distance[i]==0)
        {;
        }
        else
        {
            cout<<distance[i]*6<<" ";
        }
    }
}