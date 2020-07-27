#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<int>topk(vector<int>&,int);

int main()
{   
    int T,n,k;
    cin>>T;
    while(T--)
    {
        cin>>n;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        vector<int>a = topk(arr,k);
        for(int x : a)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
struct Pair
{
    int element,freq;
};
struct compare
{
    bool operator()(Pair &p1,Pair &p2)
    {
        if(p1.freq == p2.freq)
        {
            return p1.element < p2.element;
        }
        else
        {
            return p1.freq < p2.freq;
        }
    }
};
vector<int>topk(vector<int>&arr,int k)
{
    vector<int>result;
    priority_queue<Pair,vector<Pair>,compare>pq;
    unordered_map<int,int>um;
    for(int i=0;i<arr.size();i++)
    {
        um[arr[i]]++;
    }
    int n = um.size();
    Pair pairs[n];
    int i = 0;
    for(auto it = um.begin();it!=um.end();it++)
    {
        pairs[i].element = it->first;
        pairs[i].freq = it->second;
        i++;
    }
    for(int i(0);i<n;i++)
    {
        pq.push(pairs[i]);
    }
    int c = k;
    while(c>0)
    {
        Pair p = pq.top();
        result.push_back(p.element);
        pq.pop();
        c--;
    }
    return result;
}