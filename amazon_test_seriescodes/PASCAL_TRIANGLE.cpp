#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int);
void generate_sum(vector<int>&);
int main()
{   
    int n;
    cin>>n;
    vector<vector<int>>res = generate(n);
    for(vector<int> p : res)
    {
        for(int x : p)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
void generate_sum(vector<int>&p,vector<int>&p1)
{
    queue<int>q;
    int n = p.size();
    int current;
    q.push(p[0]);
    int i=1;
    for(;i<n;i++)
    {
        current = q.front();
        p1.push_back(current+p[i]);
        q.pop();
        q.push(p[i]);
    }
}
vector<vector<int>>generate(int numrows)
{   
    vector<vector<int>>res(numrows,vector<int>(1,1));
    if(numrows < 2)
    {
        return res;
    }
    else
    {
        res[1].push_back(1);
        for(int i=2;i<numrows;i++)
        {
            generate_sum(res[i-1],res[i]);
            res[i].push_back(1);
        }
        return res;
    }
}