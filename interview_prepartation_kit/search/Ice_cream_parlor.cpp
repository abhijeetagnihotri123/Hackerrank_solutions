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
        int v1,v2;
        for(int i=0;i<n-1;i++)
        {
            if(binsearch(b,i+1,m-b[i])!=-1)
            {
                v1=b[i];
                v2=m-b[i];
                break;
            }
        }
        vector<int>c(2);
        c[0]=indexOf(a,v1,-1);
        c[1]=indexOf(a,v2,c[0]);
        sort(c.begin(),c.end());
        cout<<c[0]+1<<" "<<c[1]+1<<endl;
    }
    return 0;
}
int binsearch(vector<int>&b,int index,int ele)
{
    int beg=index;
    int last=b.size()-1;
    int mid;
    int flag=-1;
    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(b[mid]==ele)
        {
            flag=1;
            break;
        }
        else if(b[mid]<ele)
        {
            beg=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }
    return flag;
}
int indexOf(vector<int>&a,int ele,int ITBI)
{
    int n=a.size();
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==ele && i!=ITBI)
        {
            f=i;
            break;
        }
    }
    return f;
}