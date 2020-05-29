#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
int check(unsigned long long int n)
{
    unsigned long long int m=n;
    unsigned long long int d=0;
    while(m>0)
    {
        d++;
        m=m/10;
    }
    unsigned long long int k=pow(10,d);

    unsigned long long int s=n*n;
    unsigned long long int a=s%k;
    unsigned long long int b=s/k;
    if((a+b)==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    unsigned long long int p,q;
    cin>>p>>q;
    unsigned long long int c=0;
    for(unsigned long long int i=p;i<=q;i++)
    {
        if(check(i)==1)
        {
            cout<<i<<" ";
        }
        else
        {c++;}
    }
    if(c==(q-p+1))
    {
        cout<<"INVALID RANGE";
    }
    return 0;
}

