#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    if(n>=1&&n<=60)
    {
        int grades[n];
        for(int i=0;i<n;i++)
        {
            cin>>grades[i];
        }
     for(int i=0;i<n;i++)
     {
         if(grades[i]<38)
         {cout<<grades[i]<<endl;}
         else if((grades[i]%5)>=3)
         {
             cout<<grades[i]+(5-(grades[i]%5))<<endl;
         }
        else
        {cout<<grades[i]<<endl;}
     }}      
    return 0;
}

