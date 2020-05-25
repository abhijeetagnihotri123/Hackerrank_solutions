#include<iostream>
#include<map>
#include<iterator>
using namespace std;
int main()
{
    string str;
    cin>>str;
    map<char,int>m;
    for(char ch='a';ch<='z';ch++)
    {
        m[ch]=0;
    }
    for(int i=0;i<str.length();i++)
    {
        m[str.at(i)]++;
    }
    int c=0;
    for(char ch='a';ch<='z';ch++)
    {
        if(m[ch]%2==1){c++;}
    }
    if(c>1){cout<<"NO"<<endl;}
    else{cout<<"YES"<<endl;}
    return 0;
}


