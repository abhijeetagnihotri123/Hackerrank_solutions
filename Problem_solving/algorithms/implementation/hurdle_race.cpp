#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cin>>n;
    cin>>k;
    int h[n];
    for(int i=0;i<n;i++)
    {cin>>h[i];}
    int max=h[0];
    for(int i=0;i<n;i++)
    {
        if(h[i]>max)
        {
            max=h[i];
        }
    }
    if(k>max)
    {cout<<0;
    }
    else
    {cout<<(max-k);}
    return 0;
}

