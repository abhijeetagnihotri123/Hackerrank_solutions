#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int binsearch(vector<int>&v,int &target,int &n,bool mode)
    {   
        int index = -1;
        int beg,last,mid;
        beg = 0;
        last = n-1;
        if(mode)
        {
            while(beg <= last)
            {
                mid = (beg+last);
                mid = (mid>>1);
                if(v[mid] == target && v[mid-1] != target)
                {
                    index = mid;
                    break;
                }
                else if(v[mid] == target && v[mid-1] == target)
                {
                    last = mid-1;
                }
                else if(v[mid] > target)
                {
                    last = mid-1;
                }
                else
                {
                    beg = mid+1;
                }
            }
        }
        else
        {
            while(beg <= last)
            {
                mid = (beg+last);
                mid = (mid>>1);
                if(v[mid] == target && v[mid+1] != target)
                {
                    index = mid;
                    break;
                }
                else if(v[mid] == target && v[mid+1] == target)
                {
                    beg = mid+1;
                }
                else if(v[mid] > target)
                {
                    last = mid-1;
                }
                else
                {
                    beg = mid+1;
                }
            }
        }
        return index;
    }
    vector<int>searchRange(vector<int>&nums,int target)
    {
        int n = nums.size();
        vector<int>v(2,-1);
        if(n == 0)
        {
            //do nothing
        }
        else if(n == 1)
        {
            if(nums[0] == target)
            {
                v[0] = v[1] = 0;
            }
        }
        else
        {
            v[0] = binsearch(nums,target,n,true);
            v[1] = binsearch(nums,target,n,false);
        }
        return v;
    }
};
int main()
{
    Solution ob;
    int n;
    cin>>n;
    vector<vector<int>>v(2);
    for(int i=0;i<n;i++)
    {   
        int k;
        cin>>k;
        v[0].push_back(k);
    }
    int target;
    cin>>target;
    v[1] = ob.searchRange(v[0],target);
    cout<<v[1][0]<<" "<<v[1][1];
}