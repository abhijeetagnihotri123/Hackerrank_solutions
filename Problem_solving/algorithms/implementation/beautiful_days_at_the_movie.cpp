#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int i,j,k;
    cin>>i>>j>>k;
    int c=0;
    for(int n=i;n<=j;n++)
    {
        int m=n;
        int s=0;
        while(m!=0)
        {
        int a=m%10;
        s=s*10+a;
        m=m/10;
        }
        if((abs(n-s))%k==0)
        {c++;}
    }
    cout<<c;
    return 0;
}

