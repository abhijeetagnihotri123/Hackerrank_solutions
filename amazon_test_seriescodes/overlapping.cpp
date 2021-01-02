#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int );

// User code will be pasted here

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > arr,res;
        int n,x,y;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }
        
        res = overlappedInterval(arr,n);
        
        
        for(int i=0;i<res.size();i++)
            cout <<" "<< res[i].first << " " << res[i].second << " " ;
            
        cout<<endl;
    }
}
bool compare(pair<int,int>p1, pair<int,int>p2)
{
    return p1.first < p2.first; // key of this question remember this
}
vector<pair<int,int>> overlappedInterval(vector<pair<int,int>>vec,int n)
{
    sort(vec.begin(),vec.end(),compare);
    stack<pair<int,int>>s;
    int i=1;
    s.push(vec[0]);
    for(;i<n;i++)
    {
        pair<int,int>p1 = s.top();
        pair<int,int>p2 = vec[i];
        if(p1.second > p2.first)
        {
            pair<int,int>p;
            p.first = p1.first < p2.first ? p1.first:p2.first;
            p.second = p2.second > p1.second ? p2.second:p1.second;
            s.pop();
            s.push(p);
        }
        else
        {
            s.push(p2);
        }
    }
    int number = s.size();
    i = number-1;
    vector<pair<int,int>>res(number);
    while(!s.empty())
    {
        pair<int,int>p = s.top();
        res[i]=p;
        i--;
        s.pop();
    }
    return res;
}