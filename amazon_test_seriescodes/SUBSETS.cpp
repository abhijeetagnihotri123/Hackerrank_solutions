#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>&);

int main()
{       
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<vector<int>>r = subsets(nums);
    for(vector<int>x : r)
    {
        for(int y : x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
vector<vector<int>> subsets(vector<int>& nums) 
{
    int n = nums.size();
    int N = (1<<n);
    vector<vector<int>>res;
    for(int i=0;i<N;i++)
    {   
        vector<int>r;
        int k = i;
        int index = 0;
        while(k>0)
        {
            if((k&1)>0)
            {
                r.push_back(nums[index]);
            }
            k = k>>1;
            index++;
        }
        res.push_back(r);
    }
    return res;
}    