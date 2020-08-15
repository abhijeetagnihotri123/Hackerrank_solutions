#include <bits/stdc++.h>
using namespace std;

#define SIZE 100



void mark_location(int i,int j,int r,int c,int A[SIZE][SIZE],int &count)
{
    if(i<0 || j<0 || i>=r || j>=c || A[i][j] != 1)
    {
        return;
    }
    else
    {
        A[i][j] = 0;
        count++;
        mark_location(i-1,j,r,c,A,count);
        mark_location(i+1,j,r,c,A,count);
        mark_location(i,j-1,r,c,A,count);
        mark_location(i,j+1,r,c,A,count);
        mark_location(i-1,j-1,r,c,A,count);
        mark_location(i-1,j+1,r,c,A,count);
        mark_location(i+1,j-1,r,c,A,count);
        mark_location(i+1,j+1,r,c,A,count);   
    }
}
int findMaxArea(int N,int M,int A[SIZE][SIZE])
{
    if(N==0)
    {
        return 0;
    }
    else
    {
        int c,max_area;
        max_area = 0;
        for(int i=0;i<N;i++)
        {   
            for(int j=0;j<M;j++)
            {   
                c=0;
                if(A[i][j] == 1)
                {
                    mark_location(i,j,N,M,A,c);
                }
                if(c>max_area)
                {
                    max_area = c;
                }
            }
        }
        return max_area;
    }
}   
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}