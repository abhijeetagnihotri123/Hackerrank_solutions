#include <bits/stdc++.h>
using namespace std;
int binsearch(vector<int>&,int&);
int main()
{   
    int n,m;
    cin>>n;
    vector<int>a;
    int k;
    int index=0;
    for(int i=0;i<n;i++)
    {   
        cin>>k;
        if(a.size()==0)
        {
            a.push_back(k);
        }
        else if(a[index]!=k)
        {
            a.push_back(k);
            index++;
        }
        else{;}    
    }
    cin>>m;
    vector<int>b(m,0);
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<m;i++)
    {
        cout<<binsearch(a,b[i])<<endl;
    }
    return 0;
}
int binsearch(vector<int>&a,int &ele)
{
    if(ele >= a[0])
    {
        return 1;
    }
    else if(ele < a[a.size()-1])
    {
        return (a.size()+1);
    }
    else if(ele==a[a.size()-1])
    {
        return (a.size());
    }
    else
    {
        int beg=0;
        int last=a.size()-1;
        int mid;
        int pos;
        while(beg<=last)
        {
            mid=(beg+last)/2;
            if(a[mid]==ele)
            {   
                pos=mid;
                break;
            }
            else if(ele > a[mid] && ele < a[mid-1])
            {
                pos=mid;
                break;
            }
            else if(ele>a[mid])
            {
                last=mid-1;
            }
            else
            {
                beg=mid+1;
            }
            
        }
        return (pos+1);
    }
    return 0;
}
