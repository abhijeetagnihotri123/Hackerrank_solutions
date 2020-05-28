#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n,k,b;
    cin>>n;
    cin>>k;
    int c[n];
    for(int i=0;i<n;i++)
    {cin>>c[i];}
    cin>>b;
    double s=0;
    double sp=0;
    for(int i=0;i<n;i++)
    {
        if(i!=k)
        {
            s=s+c[i];
        }
        else{}
    }
    sp=s/2;
    if(sp==b)
    {cout<<"Bon Appetit";}
    else
    {   
        if(sp>b)
        {cout<<(sp-b);}
        else
        {cout<<(b-sp);}
    }return 0;}
