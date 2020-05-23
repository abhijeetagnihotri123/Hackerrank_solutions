#include <bits/stdc++.h>
using namespace std;

int BFS(vector<vector<int>>&,int,bool*);
int main()
{   
    int n;
    cin>>n;
    int m=n;
    int max=0;
    int min=2*n;
    vector<vector<int>>graph(2*n,vector<int>());
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    bool visited[2*n]={false};
    //cout<<BFS(graph,2,visited)<<endl<<BFS(graph,3,visited)<<endl<<BFS(graph,0,visited);
    //bool visited[2*n]={false};
    for(int i=0;i<2*n;i++)
    {   
        if(visited[i]==false)
        {   
            m=BFS(graph,i,visited);
            if(m > max)
            {
                max=m;
            }
            if(m>1 && min>m)
            {
                min=m;
            }
        }
    }
    cout<<min<<" "<<max;
    return 0;
}
int BFS(vector<vector<int>>&graph,int s,bool *visited)
{   
    int c=0;
    queue<int>Q;
    Q.push(s);
    visited[s]=true;
    while(!Q.empty())
    {
        int current=Q.front();
        Q.pop();
        c++;
        for(int i=0;i<graph[current].size();i++)
        {
            if(!visited[graph[current][i]])
            {
                Q.push(graph[current][i]);
                visited[graph[current][i]]=true;
            }
        }
    }
    return c;
}

