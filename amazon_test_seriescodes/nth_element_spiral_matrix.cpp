#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}// } Driver Code Ends


/*You are required to complete this method*/
int findK(int a[MAX][MAX], int n, int m, int k)
{   
    if(n<1 && m<1)
    {
        return -1;
    }
    else if(k<=m)
    {
        return a[0][k-1];
    }
    else if(m<k && k<=(n+m-1))
    {
        return a[k-m][m-1];
    }
    else if((n+m-1)<k && k<=(2*m+n-2))
    {
        return a[n-1][(m-1)-(k-(n+m-1))];
    }
    else if((2*m+n-2)<k && k<=(2*n+2*m-4))
    {
        return a[(n-1)-(k-(2*m+n-2))][0];
    }
    else
    {
        return findK((int(*)[MAX])(&(a[1][1])),n-2,m-2,k-(2*m+2*n-4));//remember this how to pass a submatrix
    }
}

