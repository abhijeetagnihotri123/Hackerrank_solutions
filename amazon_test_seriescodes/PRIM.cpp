#include <bits/stdc++.h>
using namespace std;


int spanningTree(int,int,vector<vector<int>>&);
int main()
{
    int t;
    int V = 6;
    int graph1[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0}};
    vector<vector<int>>graph(V,vector<int>(V,0));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            graph[i][j] = graph1[i][j];
        }
    }
    cout<<spanningTree(V,V,graph);
    return 0;
}
int selectMinVertex(vector<int>&value,vector<bool>&setMST)
{
    int minimum = INT_MAX;
    int vertex;
    int V = value.size();
    for(int i=0;i<V;i++)
    {
        if(setMST[i] == false && value[i] < minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}
int spanningTree(int V,int E,vector<vector<int>>&graph)
{
    int parent[V];
    vector<int>value(V,INT_MAX);
    vector<bool>setMST(V,false);
    parent[0] = -1;
    value[0] = 0;
    for(int i=0;i<V;i++)
    {
        int U = selectMinVertex(value,setMST);
        setMST[U] = true;
        for(int j=0;j<V;j++)
        {
            if(graph[i][j] != 0 && setMST[j] == false && graph[U][j] < value[j])
            {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }
    int sum = 0;
    for(int i=1;i<V;i++)
    {
        //    cout<<parent[i]<<" "<<i<<" "<<graph[i][parent[i]]<<endl;
        sum += graph[i][parent[i]];
    }
    return sum;
}