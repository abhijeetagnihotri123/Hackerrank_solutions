#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int t;
    cin>>n>>t;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(t--)
    {
        int i,j;
        cin>>i>>j;
        vector<int>v(j-i+1);
        for(int k=i;k<=j;k++)
        {
            v[k-i]=a[k];
        }
        sort(v.begin(),v.end());
        cout<<v[0];
        cout<<endl;    
    }
    return 0;
}

