#include <iostream>
#include <vector>
using namespace std;
int min_cost_aux(vector<vector<int>>&,int,int,int&);
int min_cost(vector<vector<int>>&,int&);
int min(int,int,int,int);
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    int m = n-1;
    cout<<min_cost(grid,m);
}
int min(int w,int x)
{
    return w<=x ? w:x;
}
int min_cost_aux(vector<vector<int>>&grid,int n,int m,int &size)
{   

   if (n < 0 || m < 0)
   { 
      return 2147483647; 
   }
   else if(n>=size || m>=size)
   {
       return 2147483647;
   }
   else if (m == 0 && n == 0) 
   {
      return grid[m][n]; 
   }
   else
    {   return grid[m][n] + min(min_cost_aux(grid, m-1, n,size),min_cost_aux(grid, m, n-1,size));
    }
}
int min_cost(vector<vector<int>>&grid,int &n)
{   
    return min_cost_aux(grid,n-1,n-1,n);
}