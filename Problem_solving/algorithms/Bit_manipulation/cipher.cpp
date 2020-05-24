#include <iostream>
using namespace std;
int main()
{   
    int n,k,res;
    cin>>n>>k;
    int *a,*b;
    a=new int[n+k-1];
    b=new int[n];
    for(int i=0;i<n+k-1;i++)
    {   
        char ch;
        cin>>ch;
        a[i]=int(ch)-48;
    }
    b[0]=a[0];
    res=0;
    for(int i=1;i<n;i++)
    {
        if(i<k)
        {
            res=b[i-1]^res;
            b[i]=a[i]^res;
        }
        else
        {
            b[i]=a[i]^a[i-1]^b[i-k];   
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i];
    }
    delete(a);
    delete(b);
    return 0;
}
