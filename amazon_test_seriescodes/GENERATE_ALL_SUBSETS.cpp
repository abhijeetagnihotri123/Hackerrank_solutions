#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>getSubsets(vector<int>&);

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }   
    vector<vector<int>>res = getSubsets(v);
    for(vector<int> x : res){
        for(int y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
vector<vector<int>>getSubsets(vector<int>&s)
{
    int n = s.size();
    int N = (1<<n);
    vector<vector<int>>res;
    for(int i=0;i<N;i++)
    {
        vector<int>subset;
        int k = i;
        int index = 0;
        while(k>0)
        {
            if((k&1)>0){
                subset.push_back(s[index]);
            }
            k = k>>1;
            index++;
        }
        res.push_back(subset);
    }
    return res;
}