#include <bits/stdc++.h>
#define MAX_INT 2147483647
using namespace std;
int V, E;
int mst_wt(vector<vector<pair<int, int>>> &);
void addEdge(int, int, int, vector<vector<pair<int, int>>> &);
int main() {
  cin >> V >> E;
  vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());
  int u, v, w;
  while (E--) {
    cin >> u >> v >> w;
    u--;
    v--;
    addEdge(u, v, w, graph);
  }
  cout << mst_wt(graph);
  return 0;
}
void addEdge(int u, int v, int w, vector<vector<pair<int, int>>> &graph) {
  graph[u].push_back(make_pair(w, v));
  graph[v].push_back(make_pair(w, u));
}
int mst_wt(vector<vector<pair<int, int>>> &graph) {
  int mst = 0;
  vector<int> key(V, MAX_INT);
  vector<bool> inmst(V, false);
  vector<int> parent(V, -1);
  int src = 0;
  key[src] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, src));
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    inmst[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].second;
      int w = graph[u][i].first;
      if (inmst[v] == false && key[v] > w) {
        key[v] = w;
        pq.push(make_pair(key[v], v));
        parent[v] = u;
      }
    }
  }
  
  for (int i = 0; i < V; i++) {
    mst += key[i];
  }
  return mst;
}
