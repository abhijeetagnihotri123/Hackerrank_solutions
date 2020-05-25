#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100]={0};
    int len=1;
    a[0]=1;
    int carry;
    int mul;
    int digit;
    for(int i=2;i<=n;i++)
    {
        carry=0;
        for(int j=0;j<len;j++)
        {
            mul=a[j]*i+carry;
            digit=mul%10;
            a[j]=digit;
            carry=mul/10;
        }
        while(carry>0)
        {
            len++;
            digit=carry%10;
            a[len-1]=digit;
            carry=carry/10;
        }
    }
    for(int i=len-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}


