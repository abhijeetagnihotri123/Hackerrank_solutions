#include <bits/stdc++.h>
using namespace std;

int root(int i,vector<int>&parent)
{
    while(i != parent[i])
    {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}
bool find(int A,int B,vector<int>&parent)
{
    if(root(A,parent) == root(B,parent))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Union(int A,int B,vector<int>&parent)
{
    if(find(A,B,parent))
    {
        return ;
    }
    else
    {
        int root_A = root(A,parent);
        int root_B = root(B,parent);
        parent[root_B] = parent[root_A];
        root_B = root(root_B,parent);   
    }
}
void BFS(vector<int>g[],int s,vector<bool>&visited,vector<int>&parent,bool &flag)
{
    queue<int>q;
    q.push(s);
    int current,u,v;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        u = g[current][0];
        for(int i=0;i<g[current].size();i++)
        {
            v = g[current][i];
            if(!visited[v])
            {
                q.push(v);
                visited[v] = true;
                Union(u,v,parent);
            }
            else
            {
                int root_A = root(u,parent);
                int root_B = root(v,parent);
                if(find(root_A,root_B,parent))
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
        {
            break;
        }
    }
}
bool isCyclic(vector<int>g[],int V)
{   
    vector<int>parent(V,-1);
    for(int i=0;i<V;i++)
    {
        parent[i] = i;
    }
    vector<bool>visited(V,false);
    bool flag = false;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && !flag)
        {
            BFS(g,i,visited,parent,flag);
        }
    }
    return flag;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
    return 0;
}