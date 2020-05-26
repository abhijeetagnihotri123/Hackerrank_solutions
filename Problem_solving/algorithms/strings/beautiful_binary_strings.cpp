#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int c=0;
    int i=0;
    while(i<=n-3)
    {
        if(str.substr(i,3)=="010")
        {
            c++;
            i=i+3;
        }
        else
        {
            i++;
        }
    }
    cout<<c;
    return 0;
}
