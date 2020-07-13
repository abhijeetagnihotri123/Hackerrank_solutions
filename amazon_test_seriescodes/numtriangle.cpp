#include <bits/stdc++.h>
using namespace std;
long long findNumberOfTriangles(long long n)
{
    sort(arr,arr+n);
    long long count = 0;
    for(int i=0;i<n-2;i++)
    {
        int k = i+2;
        for(int j=i+1;j<n;j++)
        {
            while(k<n && arr[i]+arr[j]>arr[k])
            {
                k++;
            }
            if(k>j)
            {
                count += k-j-1;
            }
        }
    }
    return count;
}
int main()
{
    long long size,T;
    
    cin>>T;

    while(T--){
        
    cin>>size;

    for(int i=0;i<size;i++)
     cin>>arr[i];
     
    cout<<findNumberOfTriangles(size ) <<endl;
    }
    return 0;
}

