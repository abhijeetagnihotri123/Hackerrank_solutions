#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i(0);i<n;i++)
        {
            cin>>a[i];
        }
        int t[n];
        for(int i(0);i<n;i++)
        {
            if((i-k)<0)
            {
                t[i-k+n]=a[i];
            }
            else
            {
                t[i-k]=a[i];
            }
        }
    for(int i(0);i<n;i++)
    {
        cout<<t[i]<<" ";
    }
    return 0;
}

