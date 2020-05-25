#include <iostream>
#include <string>
#include <vector>
#define N 20
using namespace std;
int main()
{   
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(N,vector<char>(N,' '));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int max=0;
    int r;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {   
            r=0;
            while(grid[i-r][j]=='G'&&grid[i+r][j]=='G'&&grid[i][j+r]=='G'&&grid[i][j-r]=='G')
            {   
                grid[i-r][j]=grid[i+r][j]=grid[i][j-r]=grid[i][j+r]='g';
                for(int p=1;p<=n;p++)
                {
                    for(int q=1;q<=m;q++)
                    {   
                        int R=0;
                        while(grid[p][q-R]=='G'&&grid[p][q+R]=='G'&&grid[p-R][q]=='G'&&grid[p+R][q]=='G')
                        {
                            if(max<(1+4*r)*(1+4*R))
                            {
                                max=(1+4*r)*(1+4*R);
                            }
                            R++;
                        }
                    }
                }    
                r++;
            }
            r=0;
            while(grid[i-r][j]=='g'&&grid[i+r][j]=='g'&&grid[i][j+r]=='g'&&grid[i][j-r]=='g')
            {
                grid[i-r][j]=grid[i+r][j]=grid[i][j-r]=grid[i][j+r]='G';
                r++;
            }
        }
    }
    cout<<max;
    return 0;
}

