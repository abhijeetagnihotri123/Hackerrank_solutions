#include<iostream>
#include<string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int c=0;
        string str;
        cin>>str;
        int n=str.length();
        string strrev="";
        for(int i=n-1;i>=0;i--)
        {
            strrev=strrev+str.at(i);
        }
        for(int i=0;i<n-1;i++)
        {
            if(abs(str.at(i)-str.at(i+1))==abs(strrev.at(i)-strrev.at(i+1)))
            {
                c++;
            }
        }
        if(c==n-1)
        {
            cout<<"Funny";
        }
        else
        {
            cout<<"Not Funny";
        }
        cout<<endl;
    }
    return 0;
}

