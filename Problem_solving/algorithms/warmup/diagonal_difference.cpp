#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n;
    int s;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {cin>>a[i][j];}
    }
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++)
    {
        c1=c1+a[i][i];
    }
    int k=n-1;
    for(int i=0;i<n;i++)
    {
        c2=c2+a[i][k];
        k--;
    }
    if(c1>c2)
    {s=c1-c2;}
    else
    {s=c2-c1;}
    cout<<s;
    return 0;
}