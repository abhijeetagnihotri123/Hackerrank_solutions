#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int s,t,a,b;
    cin>>s>>t;
    cin>>a>>b;
    if((a<s)&&(s<t)&&(t<b))
    {
    int m,n;
    cin>>m>>n;
    int M[m];
    int N[n];
    for(int i=0;i<m;i++)
    {cin>>M[i];}
    for(int i=0;i<n;i++)
    {cin>>N[i];}
        int c1=0;
        int c2=0;
    for(int i=0;i<m;i++)
    {M[i]=M[i]+a;
    if((M[i]>=s)&&(M[i]<=t))
    {c1++;}
    }
    for(int i=0;i<n;i++)
    {N[i]=N[i]+b;
    if((N[i]>=s)&&(N[i]<=t))
    {c2++;}
    }
 cout<<c1<<endl;
        cout<<c2;
    }
    else{}
    return 0;
}

