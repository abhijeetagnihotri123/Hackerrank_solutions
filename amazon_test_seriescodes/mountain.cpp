#include <iostream>
using namespace std;
bool processQueries(int *,int&,int&,int&);
int main()
{   
    int T,n,m,u,v;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int *a;
        a = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        while(m--)
        {
            cin>>u>>v;
            if(processQueries(a,n,u,v))
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        delete(a);
    }
    return 0;
}
bool processQueries(int *a,int &n,int &u,int &v)
{
    bool result = false;
    if(v == (u+1))
    {
        result = a[v]>=a[u];
    }
    else
    {
        int index = u;
        while(a[index]<=a[index+1] && index <v)
        {   
            index++;
        }
        if(index != v)
        {
            while(a[index]>=a[index+1] && index <v)
            {
                index++;
            }
            if(index == v)
            {
                result = true;
            }
        }
        else
        {
            result = false;
        }
    }
    return result;
}