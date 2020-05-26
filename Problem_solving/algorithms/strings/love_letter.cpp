#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        string str;
        cin>>str;
        int n=str.length();
        int s=0;
        for(int i=0;i<n/2;i++)
        {
            s=s+abs((int)(str.at(i)-str.at(n-i-1)));
        }
        cout<<s<<endl;
    }
    return 0;
}

