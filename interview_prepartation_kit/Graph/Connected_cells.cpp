#include <bits/stdc++.h>
using namespace std;
int findregionsize(vector<vector<int>>&,int,int,int,int);
int main()
{   
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j]; 
        }
    }
    int maxarea=0;
    int area=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                area=findregionsize(grid,i,j,n,m);
                if(area>=maxarea)
                {
                    maxarea=area;
                }
            }
        }
    }
    cout<<maxarea;
    return 0;
}
int findregionsize(vector<vector<int>>&grid,int row,int col,int rsize,int csize)
{
    if(row<0 || col < 0 || row>=rsize || col>=csize)
    {
        return 0;
    }
    else if(grid[row][col]==0)
    {
        return 0;
    }
    else
    {
        int size = 1;
        grid[row][col]=0;
        for(int r=row-1;r<=row+1;r++)
        {
            for(int c=col-1;c<=col+1;c++)
            {
                if(r!=row || c!=col)
                {
                    size+=findregionsize(grid,r,c,rsize,csize);
                }
            }
        }
        return size;
    }
}
