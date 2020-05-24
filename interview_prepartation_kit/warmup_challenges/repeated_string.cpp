#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int noofa(string str)
{
    int c=0;
    for(int i=0;i<str.length();i++)
    {
        if(str.at(i)=='a')
        {
            c++;
        }
    }
    return c;
}
int main() {
    string str;
    unsigned long long int n;
    cin>>str;
    cin>>n;
    unsigned long long int s=str.length();
    unsigned long long int c=0;
    if(n%s==0)
    {
        c=n/s;
        c=c*noofa(str);
    }
    else
    {
        c=n/s;
        c=c*noofa(str)+noofa(str.substr(0,n%s));
    }
    cout<<c;
    return 0;
}
