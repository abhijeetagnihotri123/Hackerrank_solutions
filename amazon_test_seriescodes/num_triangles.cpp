#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{       
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int count = 0;
    for(int i=0;i<n-2;i++)
    {
        int k = i+2;
        for(int j=i+1;j<n;j++)
        {
            while(k<n && a[i]+a[j]>a[k])
            {
                ++k;
            }
            if(k>j)
            {
                count+=k-j-1;
            }
        }
    }
    cout<<count;
    return 0;
}