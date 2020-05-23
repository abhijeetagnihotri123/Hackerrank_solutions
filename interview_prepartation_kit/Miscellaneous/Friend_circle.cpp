#include <bits/stdc++.h>

using namespace std;

map<int,int>size;
map<int,int>parent;
int m=0;
// Complete the maxCircle function below.
int root(int);
bool find(int,int);
void weighted_union(int,int);
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    vector<int>result;
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
            parent[queries[i][j]]=queries[i][j];
            size[queries[i][j]]=1;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for(int i=0;i<queries.size();i++)
    {
        weighted_union(queries[i][0], queries[i][1]);
        result.push_back(m);
    }
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
        if(size[root_A] <= size[root_B])
        {
            parent[root_A]=parent[root_B];
            size[root_B]+=size[root_A];
            root_A=root(root_A);
            if(size[root_B]>m)
            {
                m=size[root_B];
            }
        }
        else
        {
            parent[root_B]=parent[root_A];
            size[root_A]+=size[root_B];
            root_B=root(root_B);
            if(size[root_A]>m)
            {
                m=size[root_A];
            }
        }
    }
}
