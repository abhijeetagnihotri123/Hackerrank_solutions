#include <bits/stdc++.h>
using namespace std;
map<int,int>size;
map<int,int>parent;
int m=0;
int root(int);
bool find(int,int);
void weighted_union(int,int);
int main()
{   
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        size[i]=1;
        parent[i]=i;
    }
    while(m--)
    {   
        char Q;
        cin>>Q;
        if(Q=='Q')
        {
            cin>>a;
            int r=root(a);
            cout<<size[r]<<endl;
        }
        else
        {   
            cin>>a>>b;
            weighted_union(a,b);
        }
    }
    return 0;
}
int root(int i)
{
    while(parent[i]!=i)
    {
        parent[i]=parent[parent[i]];
        i=parent[i];
    }
    return i;
}
bool find(int A,int B)
{
    if(root(A)==root(B))
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void weighted_union(int A,int B)
{
    if(find(A,B))
    {
        return ;
    }
    else
    {
        int root_A=root(A);
        int root_B=root(B);
        parent[root_B]=parent[root_A];
        size[root_A]+=size[root_B];
        root_B=root(root_B);
    }
}

