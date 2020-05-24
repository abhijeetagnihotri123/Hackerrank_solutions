#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int n;
    cin>>n;
    if((n>=1)&&(n<=100000))
    {   int c=0;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int max=a[0];
     for(int i=1;i<n;i++)
     {
         if(a[i]>max)
         {
             max=a[i];
         }
     }
     for(int i=0;i<n;i++)
     {
         if(a[i]==max)
         {
             c++;
         }
     }
     cout<<c;
    }
    return 0;
}
