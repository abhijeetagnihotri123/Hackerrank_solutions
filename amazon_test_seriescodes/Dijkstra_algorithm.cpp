#include <bits/stdc++.h>
using namespace std;

vector<int>dijkstra(vector<vector<int>>& , int ,int);

void printSolution(vector<int>dist,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",dist[i]);
    }
    printf("\n");
}

int main()
{   
    int t,V;
    cin>>t;
    while(t--)
    {
        cin>>V;
        vector<vector<int>>g(V,vector<int>(V,0));
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cin>>g[i][j];
            }
        }
        int s;
        cin>>s;
        vector<int>res = dijkstra(g,s,V);
        printSolution(res,V);
    }
    return 0;
}
int selectMinVertex(int &V,vector<int>&d,vector<bool>&processed)
{
    int minimum = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(minimum > d[i] && !processed[i])
        {
            minimum = d[i];
            vertex = i;
        }
    }
    return vertex;
}
vector<int> dijkstra(vector<vector<int>>&g,int s,int V)
{
    vector<bool>processed(V,false);
    vector<int>d(V,INT_MAX);
    vector<int>parent(V,-1);
    d[s] = 0;
    int U;// = selectMinVertex(V,d,processed);
    for(int i=0;i<V-1;i++)
    {
        U = selectMinVertex(V,d,processed);
        processed[U] = true;
        for(int j=0;j<V;j++)
        {
            if(g[U][j] != 0 && !processed[j] && d[U] != INT_MAX && (d[U] + g[U][j])<d[j])
            {
                d[j] = d[U] + g[U][j];
                parent[j] = U;
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        cout<<d[i]<<" ";
    }
    return d;
}