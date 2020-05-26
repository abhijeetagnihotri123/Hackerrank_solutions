#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int c=0;
        for(int i=0;i<str.length()-1;i++)
        {
            if(str.at(i)==str.at(i+1))
            {

                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}

