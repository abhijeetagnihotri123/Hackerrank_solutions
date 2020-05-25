#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int ele,n;
    cin>>ele>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int beg=0;
    int last=n-1;
    int mid;
    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(a[mid]==ele)
        {
            cout<<mid;
            break;
        }
        else if(a[mid]>ele)
        {
            last=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    return 0;
}

