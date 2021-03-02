#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);
int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
void swap(int &a,int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    if(n == 1)
    {
        return ;
    }
    else
    {   
        int m = n>>1;
        int i0 = 0;
        while(i0 < m)
        {
            swap(matrix[i0][i0],matrix[i0][n-1-i0]);
            swap(matrix[n-1-i0][i0],matrix[i0][n-1-i0]);
            swap(matrix[i0][n-1-i0],matrix[n-1-i0][n-1-i0]);
            int i;
            for(i=i0+1;i<n-1-i0;i++)
            {
                swap(matrix[i0][i],matrix[n-i-1][i0]);
                swap(matrix[i0][i],matrix[i][n-1-i0]);
                swap(matrix[i][n-1-i0],matrix[n-1-i0][n-i-1]);
            }
            i0++;
        }
        return;
    }
}