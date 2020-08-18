#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,wt;
};

bool compare(Edge e1,Edge e2)
{
    return e1.wt<e2.wt;
}
int root(int i,vector<int>&parent)
{
    while(i != parent[i])
    {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}
bool Find(int A,int B,vector<int>&parent)
{
    bool flag = false;
    if(root(A,parent) == root(B,parent))
    {
        flag = true;
    }
    return flag;
}
void Union(int A,int B,vector<int>&parent)
{
    if(!Find(A,B,parent))
    {
        int root_A = root(A,parent);
        int root_B = root(B,parent);
        parent[root_B] = parent[root_A];
        root_B = root(root_B,parent);
    }
}
void printMst(vector<Edge>&result,int V)
{
    for(int i=0;i<V-1;i++)
    {
        cout<<result[i].src<<" "<<result[i].dest<<" "<<result[i].wt<<endl;
    }
}
void Kruskal(vector<Edge>&edge_list,int V,int E)
{
    sort(edge_list.begin(),edge_list.end(),compare);
    vector<int>parent(V,-1);
    for(int i=0;i<V;i++)
    {
        parent[i] = i;
    }
    vector<Edge>result;
    int i,j;
    i = j = 0;
    while(i<V-1 && j<E)
    {
        int u = edge_list[j].src;
        int v = edge_list[j].dest;
        if(!Find(u,v,parent))
        {
            Union(u,v,parent);
            result.push_back(edge_list[j]);
            i++;
        }
        j++;
        continue;
    }
    printMst(result,V);
}
int main()
{
    int V,E,u,v,w;
    cout<<"Enter number of vertices"<<endl;
    cin>>V;
    cout<<"Enter number of edges"<<endl;
    cin>>E;
    vector<Edge>edge_list;
    for(int i=0;i<E;i++)
    {
        Edge temp;
        cin>>u>>v>>w;
        temp.src=u;
        temp.dest=v;
        temp.wt=w;
        edge_list.push_back(temp);
    }    
    Kruskal(edge_list,V,E);
}

