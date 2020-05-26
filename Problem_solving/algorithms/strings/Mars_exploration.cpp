#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    string ExpectedSignal="";
    for(int i=0;i<n/3;i++)
    {
        ExpectedSignal="SOS"+ExpectedSignal;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
    if(str.at(i)!=ExpectedSignal.at(i))
    {
        c++;
    }
    }
    cout<<c;
    return 0;
}
