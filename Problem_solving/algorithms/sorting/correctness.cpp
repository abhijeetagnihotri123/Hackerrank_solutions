#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i(0);i<n;i++)
    {
        cin>>a[i];
    }
    int value,h;
    for(int i(1);i<n;i++)
    {
        value=a[i];
        int h=i;
        while(h > 0 && a[h-1] > value)
        {
            a[h]=a[h-1];
            h=h-1;
        }
        a[h]=value;
    }
    for(int i(0);i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

