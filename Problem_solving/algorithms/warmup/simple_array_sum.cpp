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
    int c=0;
    for(int i=0;i<n;i++)
    {cin>>a[i];}
    for(int i=0;i<n;i++)
    {c=c+a[i];}
    cout<<c;
        return 0;
}
