#include <bits/stdc++.h>

using namespace std;

#define edge pair<int, int>

void AddWeightedEdge(int u, int v, int w, vector<pair<int, edge>> &G) {
  G.push_back(make_pair(w, make_pair(u, v)));
}
void union_set(int u, int v, vector<int> &parent) { parent[u] = v; }
int find_set(int i, vector<int> &parent) {
  if (i == parent[i]) {
    return i;
  } else {
    return find_set(parent[i], parent);
  }
}
void kruskal(vector<pair<int, edge>> G, vector<pair<int, edge>> &T,
             vector<int> &parent) {
  int i, uRep, vRep;
  sort(G.begin(), G.end());
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first, parent);
    vRep = find_set(G[i].second.second, parent);
    if (uRep != vRep) {
      T.push_back(G[i]);
      union_set(uRep, vRep, parent);
    }
  }
}
int main() {

  int n, m;
  cin >> n >> m;
  vector<pair<int, edge>> G; // graph
  vector<pair<int, edge>> T; // mst
  vector<int> parent(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    AddWeightedEdge(u, v, w, G);
  }
  kruskal(G, T, parent);
  long s1 = 0;
  int i = 0;
  for (i = 0; i < T.size(); i++) {
    s1 = s1 + T[i].first;
  }
  cout << s1;
  return 0;
}
