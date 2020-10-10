#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

int getId(int M[MAX][MAX],int n)
{
    int start = 0;
    int end = n-1;
    while(start < end)
    {
        if(M[start][end] == 1)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    for(int i=0;i<n;i++)
    {
        if( i!=start && (M[start][i] == 1 || M[i][start] == 0))
        {
            return -1;
        }
    }
    return start;
}