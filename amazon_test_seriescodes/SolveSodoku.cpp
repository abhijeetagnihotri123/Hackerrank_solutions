#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9

class Solution {
  public:
    bool issafe(int grid[N][N],int row,int col,int num)
{   
    bool result = true;
    for(int i=0;i<=8;i++)
    {
        if(grid[row][i] == num)
        {
            result = false;
            break;
        }
    }
    for(int i=0;i<=8;i++)
    {
        if(grid[i][col] == num)
        {
            result = false;
            break;
        }
    }
    int SR = row-row%3;
    int SC = col-col%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i+SR][j+SC] == num)
            {
                result = false;
            }
        }
    }
    return result;
}
bool solve(int grid[N][N] , int row , int col)
{
    if(row == N-1 && col == N)
    {
        return true;
    }
    if(col == N)
    {
        row++;
        col = 0;
    }
    if(grid[row][col] > 0)
    {
        return solve(grid,row,col+1);
    }
    for (int num = 1; num <= N; num++)
    {
        if (issafe(grid, row, col, num))
        {
            grid[row][col] = num;
           
            if (solve(grid, row, col + 1))
            {   
                return true;
            }
        }
        grid[row][col] = 0;
    }
    return false;
}
bool SolveSudoku(int grid[N][N])  
{ 
    return solve(grid,0,0);
}

void printGrid (int grid[N][N]) 
{
    // Your code here 
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" "; 
        }
        
    }
    
}

};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
} 