#include <iostream>
using namespace std;
int main()
{   
    int n,m,x;
    cin>>n>>m;
    int **a;
    a = new int*[n];
    int result=0;
    for(int i=0;i<n;i++)
    {
        a[i] = new int[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>x;
    if(x < a[0][0] || x > a[n-1][m-1])
    {
        result = 0;
    }
    else if(x == a[0][0] || x == a[n-1][m-1])
    {
        result = 1;
    }
    else if(n == 1 && m == 1)
    {
        if(a[0][0] == x)
        {
            result=1;
        }
    }
    else if(n == 1 && m != 1)
    {
        for(int i=0;i<m;i++)
        {
            if(a[0][i] == x)
            {
                result=1;
                break;
            }
        }
    }
    else if(n != 1 && m == 1)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i][0] == x)
            {
                result = 1;
                break;
            }
        }
    }
    else
    {   
        if(x > a[n-1][0])
        {
            for(int i=0;i<m;i++)
            {
                if(x == a[n-1][i])
                {
                    result = 1;
                    break;
                }
            }
        }
        else
        {   
            int index,i;
            for(i=0;i<n-1;i++)
            {
                if(a[i][0] == x)
                {
                    result = 1;
                    break;
                }
                else if(a[i][0] < x && a[i+1][0] > x)
                {
                    index = i;
                    break;
                }
            }
            for(int j=0;j<m;j++)
            {
                if(a[i][j] == x)
                {
                    result = 1;
                    break;
                }
            }
        } 
    }
    cout<<result;
    for(int i=0;i<n;i++)
    {
        delete(a[i]);
    }
    delete(a);
    return 0;
}