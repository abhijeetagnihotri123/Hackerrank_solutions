#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    float a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    float sp=0,sn=0,so=0;
    float SP,SN,SO;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            sp++;
        }
        else if(a[i]<0)
        {
            sn++;
        }
        else{so++;}
    }
    SP=sp/n;
    SN=sn/n;
    SO=so/n;
    cout<<SP<<endl;
    cout<<SN<<endl;
    cout<<SO<<endl;
return 0;
}