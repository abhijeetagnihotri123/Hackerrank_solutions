#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>&p1,pair<int,int>&p2)
{
    return p1.first < p2.first;
}
int max(int &a,int &b)
{
    return a>=b?a:b;
}
vector<pair<int,int>> overlappingInterval(vector<pair<int,int>> &vec,int n)
{
    sort(vec.begin(),vec.end(),compare);
    int i=0;
    stack<pair<int,int>>s;
    pair<int,int>p1,p2,p;
    s.push(vec[i]);
    for(int i=1;i<n;i++)
    {
        p1 = s.top();
        p2 = vec[i];
        if(p1.second >= p2.first)
        {   
            int a = p1.second;
            int b = p2.second;
            p1.second = max(a,b);
            s.pop();
            s.push(p1);
        }
        else
        {
            s.push(p2);
        }
    }
    vector<pair<int,int>>result(s.size());
    int c = s.size()-1;
    while(!s.empty())
    {
        p = s.top();
        result[c] = p;
        c--;
        s.pop();
    }
    return result;
}
int main()
{   
    int t,n,x,y;
    cin>>t;
    while(t--)
    {   
        vector<pair<int,int>>arr,res;   
        pair<int,int>p;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            p.first = x;
            p.second = y;
            arr.push_back(p);
        }
        res = overlappingInterval(arr,n);
        for(int i=0;i<res.size();i++)
        {
            p = res[i];
            cout<<p.first<<" "<<p.second<<" ";
        }
        cout<<endl;
    }
    return 0;
}