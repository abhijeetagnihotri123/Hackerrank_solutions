#include <bits/stdc++.h>
using namespace std;
void superDigit(unsigned long long int n)
{
    if(n<10)
    {   
        cout<<n;
        return;
    }
    else
    {   
        unsigned long long int s=0;
        while(n>0)
        {
            int a=n%10;
            s=s+a;
            n=n/10;
        }
        superDigit(s);
    }
}
int main()
{       
    string str;
    unsigned long long int  k;
    cin>>str>>k;
    int n=str.length();
    unsigned long long int s=0;
    for(int i=0;i<n;i++)
    {
        s+=(int)str[i]-48;
    }
    superDigit((s*k));
    return 0;
}

