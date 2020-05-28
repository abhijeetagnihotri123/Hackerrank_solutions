#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int s[n];
    for(int i(0);i<n;i++)
    {
        cin>>s[i];
    }
    int max=s[0];
    int min=s[0];
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>max){c1++;max=s[i];}
        else if(s[i]<min){c2++;min=s[i];}
        else{}
    }
    cout<<c1<<" "<<c2;
    return 0;
}

