#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int n;
    cin>>n;
    char c[n];
    for(int i=0;i<n;i++)
    {cin>>c[i];}
    int v=0;
    int lvl=0;
    for(int i=0;i<n;i++)
    {
        if(c[i]=='U'||c[i]=='u')
        {++lvl;}
        if(c[i]=='D'||c[i]=='d')
        {--lvl;}
        if(lvl==0&&(c[i]=='U'||c[i]=='u'))
        {v++;}
    }
    cout<<v;
    return 0;
}

