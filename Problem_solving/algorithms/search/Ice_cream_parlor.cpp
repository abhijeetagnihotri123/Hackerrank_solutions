#include <bits/stdc++.h>
using namespace std;
int binsearch(vector<int>&,int,int);
int indexOf(vector<int>&,int,int);
int main()
{   
    int t;
    cin>>t;
        while(t--)
        {
        int m,n;
        cin>>m>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b.begin(),b.end());
        int location;
        int v1,v2;
        for(int i=0;i<n;i++)
        {
        location=binsearch(b,i,m-b[i]);
            if(location!=-1)
            {
                v1=b[i];
                v2=b[location];
                break;
            }
        }
        vector<int>r(2);
        r[0]=indexOf(a,v1,-1);
        r[1]=indexOf(a,v2,r[0]);
        sort(r.begin(),r.end());
        cout<<r[0]+1<<" "<<r[1]+1<<endl;
     }
    return 0;
}
int indexOf(vector<int>&a,int ele,int ITBE)
{   
    int index=-1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==ele && i!=ITBE)
        {
            index=i;
            break;
        }
    }
    return index;
}
int binsearch(vector<int>&a,int index,int ele)
{
    int beg=index+1;
    int n=a.size();
    int last=n-1;
    int mid;
    int location=-1;
    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(a[mid]==ele)
        {
            location=mid;
            break;
        }
        else if(a[mid]<ele)
        {
            beg=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }
    return location;
}
