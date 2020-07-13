#include <bits/stdc++.h>
#define N 100
using namespace std;

void printMat(int M[N][N],int row,int col)
{
    map<int,bool>m;
    for(int i=0;i<row;i++)
    {   
        int sum = 0;
        for(int j=0;j<col;j++)
        {
            sum += M[i][j] * (1 + 256*j + 256*j*j + j*j*j);
        }
        if(!m[sum])
        {   
            m[sum]=true;
            for(int j=0;j<col;j++)
            {
                cout<<M[i][j]<<" ";
            }   
            cout<<"$";
        }
    }
}
int main()
{       
    int n,m;
    cin>>n>>m;
    int M[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>M[i][j];
        }
    }
    printMat(M,n,m);
    return 0;
}