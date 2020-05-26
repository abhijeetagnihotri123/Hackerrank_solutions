#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int c=0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if(str.at(i)>='A'&&str.at(i)<='Z')
        {
            c++;
        }
    }
    cout<<(c+1);
    return 0;
}
