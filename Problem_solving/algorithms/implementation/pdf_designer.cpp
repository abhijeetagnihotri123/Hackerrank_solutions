#include<iostream>
#include<map>
#include<iterator>
#include<string>
using namespace std;
int main()
{
    map<char,int>m;
    char ch;
    int n;
    for(int i=97;i<=122;i++)
    {
        cin>>n;
        ch=(char)i;
        m[ch]=n;
    }
    string str;
    int Max=1;
    cin>>str;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if(Max<m[str.at(i)])
        {
            Max=m[str.at(i)];
        }
    }
    cout<<(Max*len);
    return 0;
}


