#include <iostream>

using namespace std;
int max(int,int);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        int *a,*b;
        a = new int[n];
        b = new int[m];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int j=0;j<m;j++)
        {
            cin>>b[j];
        }
        int i=0;
        int j=0;
        int sum=0;    
        int result = 0;
        int s1,s2;
        s1=s2=0;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                s1+=a[i];
                i++;
            }
            if(b[j]<a[i])
            {
                s2+=b[j];
                j++;
            }
            else
            {   
                result += max(s1,s2);
                s1=s2=0;
                while(i<n && j<m && a[i]==b[j])
                {
                    result+=a[i];
                    i++;
                    j++;
                }
            }
        }
        while(i<n)
        {
            s1+=a[i];
            i++;
        }
        while(j<m)
        {
            s2+=b[j];
            j++;
        }
        result += max(s1,s2);
        delete(a);
        delete(b);
        cout<<result;
    }
}
int max(int x,int y)
{
    return x>y?x:y;
}