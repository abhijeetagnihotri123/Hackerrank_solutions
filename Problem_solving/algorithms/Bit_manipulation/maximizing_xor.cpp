#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,b;
    cin>>a>>b;
    int max=a^a;
    for(int i=a;i<=b;i++)
    {
        for(int j=a;j<=b;j++)
        {
            if((i^j)>max)
            {
                max=i^j;
            }
        }
    }
    cout<<max;
    return 0;
}

