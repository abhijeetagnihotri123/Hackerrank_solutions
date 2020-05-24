#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int max_subarray_sum(vector<int>&);
int max_subsequence_sum(vector<int>&);
int main()
{   
    int T;
    cin>>T;
    int flag=0;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        int negmax,contneg=0;
        negmax=INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
            {
                contneg++;
                if(negmax<a[i])
                {
                    negmax=a[i];
                }
            }
        }
        if(contneg==n)
        {
            cout<<negmax<<" "<<negmax;
        }
        else
        {
            cout<<max_subarray_sum(a)<<" "<<max_subsequence_sum(a);
        }
        a.clear();
        cout<<endl;
    }
    return 0;
}
int max_subarray_sum(vector<int>&a)
{
    int max_so_far=INT_MIN;
    int max_at_end=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {   
        max_at_end=max_at_end+a[i];
        if(max_at_end<=0)
        {
            max_at_end=0;
        }
        if(max_so_far<max_at_end)
        {
            max_so_far=max_at_end;
        }
    }
    return max_so_far;
}
int max_subsequence_sum(vector<int>&a)
{
    vector<vector<int>>lis(a.size());
    lis[0].push_back(a[0]);
    int sum=0;
    int pos=0;
    for(int i=1;i<a.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j] && a[j]>=0 && (lis[i].size()<lis[j].size()+1))
            {
                lis[i]=lis[j];
            }
        }
        lis[i].push_back(a[i]);
    }
    vector<int>max=lis[0];
    for(vector <int> x : lis)
    {
        if(max.size() < x.size())
        {
            max=x;
        }
    }
    for(int x : max)
    {
        sum+=x;
    }
    return sum;
    lis.clear();
}
