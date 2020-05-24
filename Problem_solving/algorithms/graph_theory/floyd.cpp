#include <bits/stdc++.h>
#define INF 999999
using namespace std;
int main()
{   
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(n,INF));
    int u,v,w;
    while(m--)
    {
        cin>>u>>v>>w;
        graph[u-1][v-1]=w;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        if(graph[u-1][v-1]==INF && (u!=v))
        {
            cout<<-1<<endl;
        }
        else if(u==v)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<graph[u-1][v-1]<<endl;
        }
        
    }
    return 0;
}
