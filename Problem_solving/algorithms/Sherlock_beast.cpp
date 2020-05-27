#include <iostream>
using namespace std;
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int z=n;
        while(z>=0 && z%3!=0)
        {
            z=z-5;
        }
        if(z<0)
        {
            cout<<-1;
        }
        else
        {
            for(int i=0;i<z;i++)
            {
                cout<<5;
            }
            for(int i=0;i<n-z;i++)
            {
                cout<<3;
            }
        }
    
        cout<<endl;
    }
    return 0;
}
