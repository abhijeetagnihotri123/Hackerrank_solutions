#include <bits/stdc++.h>
#define NIL -1
using namespace std;

void find(vector<int> adj[], int N);

int main() {

    int t; // number of test cases
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m; // n- number of nodes and m- number of edges

        vector<int> adj[n + 1]; // adjacency list

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        find (adj, n);
        cout << "\n";
    }
}
void DFS_UTIL(vector<int>adj[],int u,vector<int>&time_stamp,vector<int>&low,stack<int>&s,vector<bool>&onstack,int &time)
{
    time_stamp[u] = low[u] = ++time;
    s.push(u);
    onstack[u] = true;

    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (time_stamp[v] == -1)
        {
            DFS_UTIL(adj,v,time_stamp, low, s, onstack,time);
            low[u]  = min(low[u], low[v]);
        }
        else if (onstack[v] == true)
            low[u]  = min(low[u], time_stamp[v]);
    }
    int w = 0;  
    if (low[u] == time_stamp[u])
    {
        while (s.top() != u)
        {
            w = s.top();
            cout << w << " ";
            onstack[w] = false;
            s.pop();
        }
        w = s.top();
        cout << w << ",";
        onstack[w] = false;
        s.pop();
    }
}
void find(vector<int>adj[],int N)
{
    vector<int>time_stamp(N,NIL);
    vector<int>ids(N,NIL);
    vector<int>low_links(N,NIL);
    vector<bool>onstack(N,false);
    stack<int>s;
    int time = 0;
    for(int i=0;i<N;i++)
    {
        if(time_stamp[i] == NIL)
        {
            DFS_UTIL(adj,i,time_stamp,low_links,s,onstack,time);
        }
    }
}