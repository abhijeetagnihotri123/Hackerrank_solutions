#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    long a[N];
    for(int i=0;i<N;i++)
    {cin>>a[i];}
    long s=0;
    for(int i=0;i<N;i++)
    {s=s+a[i];}
    cout<<s;
    return 0;
}
