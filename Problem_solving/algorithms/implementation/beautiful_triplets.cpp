#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binsearch(vector<int>&,int,int,int);
int main()
{
    int n,d;
    cin>>n>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        if(binsearch(v,i,n-1,v[i]+d)==1 && binsearch(v,i,n-1,v[i]+2*d))
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}
int binsearch(vector<int>&v,int beg,int last,int ele)
{
    int mid;
    int flag=0;
    while(beg <= last)
    {
        mid=beg+(last-beg)/2;
        if(v[mid]==ele)
        {
            flag=1;
            break;
        }
        else if(v[mid]>ele)
        {
            last=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

