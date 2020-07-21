#include <bits/stdc++.h>

using namespace std;

int main()
{   
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>g;
    int n = 5;
    int a[n] = {10,3,45,31,25};
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
        g.push(a[i]);
    }
    // max_heap
    while(!pq.empty())
    {
        int t = pq.top();
        cout<<t<<" ";
        pq.pop();
    }
    cout<<endl;
    while(!g.empty())
    {
        int t = g.top();
        cout<<t<<" ";
        g.pop();
    }
    return 0;
}