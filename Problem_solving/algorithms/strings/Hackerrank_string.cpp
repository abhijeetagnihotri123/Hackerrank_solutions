#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    string str;
    cin>>str;
    string R="hackerrank";
    if(str.length()<R.length())
    {
        cout<<"NO"<<endl;
    }
    else
    {
        int j=0;
        for(int i=0;i<str.length();i++)
        {
            if(j<R.length()&&str.at(i)==R.at(j))
            {
                j++;
            }
        }
        if(j==R.length())
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    }
    return 0;
}

