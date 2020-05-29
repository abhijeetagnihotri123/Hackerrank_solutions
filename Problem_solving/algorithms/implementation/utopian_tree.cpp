#include<iostream>
using namespace std;
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        int h=1;
        cin>>n;
        for(int i=1;i<=n;i++)
            {
                if(i%2==0)
                {
                    h=h+1;
                }
                else
                {
                    h=h*2;
                }
            }
        cout<<h<<endl;
    }
    return 0;
}


