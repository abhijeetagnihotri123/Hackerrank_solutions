#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}

void topological_sort(vector<int>adj[],int v,vector<bool>&visited,stack<int>&s)
{
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {
            topological_sort(adj,adj[v][i],visited,s);
        }
    }
    s.push(v);
}
vector <int> topoSort(int N, vector<int> adj[])
{
    vector<int>result;
    vector<bool>visited(N,false);
    stack<int>s;
    int ele;
    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            topological_sort(adj,i,visited,s);
        }
    }
    while(!s.empty())
    {
        ele = s.top();
        result.push_back(ele);
        s.pop();
    }
    return result;
}
