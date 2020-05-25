#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<iostream>
using namespace std;
int main()
{
    
    int n;
    cin>>n;
    int a[n];
    for(int i(0);i<n;i++)
    {
        cin>>a[i];
    }
    for(int i(1);i<n;i++)
    {
        int value=a[i];
        int h=i;
            while(h>0&&a[h-1]>value)
            {
                a[h]=a[h-1];
                h=h-1;
            }
        a[h]=value;
        for(int k(0);k<n;k++){cout<<a[k]<<" ";}
        cout<<endl;
    }
    return 0;
}


