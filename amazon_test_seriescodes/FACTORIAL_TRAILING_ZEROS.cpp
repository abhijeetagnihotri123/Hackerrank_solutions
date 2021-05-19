#include <bits/stdc++.h>
using namespace std;

int numZero(int);

int main()
{   
    int n;
    cin>>n;
    cout<<numZero(n);
    return 0;
}

int numZero(int n)
{
    int count = 0;
    if(n >= 5)
    {
        for(int i=5;n/i > 0; i = i * 5)
        {
            count += n/i;
        }
    }
    return count;
}