#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m,d;
    cin>>d>>m;
    int c=0;
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=i;j<i+m;j++)
        {
            s=s+a[j];
        }
        if(s==d)
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}

