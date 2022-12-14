#include <bits/stdc++.h>

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool issafe(bool graph[101][101],int n,int v,int color[],int c)
    {   
        bool result = true;
        for(int i=0;i<n;i++)
        {
            if(graph[v][i] && c == color[i])
            {
                result = false;
                break;
            }
        }
        return result;
    }
    
    bool graphColoringUtil(bool graph[101][101],int m,int n,int color[],int v)
    {
        if(v == n)
        {
            return true;
        }
        for(int c=1 ; c <= m ; c++)
        {
            if(issafe(graph,n,v,color,c))
            {
                color[v] = c;
                if(graphColoringUtil(graph,m,n,color,v+1))
                {
                    return true;
                }
                color[v] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        int color[n];
        for(int i=0;i<n;i++)
        {
            color[i] = 0;
        }
        return graphColoringUtil(graph,m,n,color,0);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}