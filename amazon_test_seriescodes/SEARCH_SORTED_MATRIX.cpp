#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>&,int);
int main()
{   
    int n,m,target;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    cin>>target;
    cout<<searchMatrix(v,target)<<endl;
    return 0;
}
bool searchMatrix(vector<vector<int>>&v,int target)
{   
    int n = v.size();
    int m = v[0].size();
    bool result;
    if(n == 1 && m == 1)
    {
        result = v[0][0] == target;
    }
    else if(v[0][0] > target || v[n-1][m-1] < target)
    {
        result = false;
    }
    else if(v[0][0] == target || v[0][m-1] == target || v[n-1][0] == target || v[n-1][m-1] == target)
    {
        result = true;
    }
    else
    {
        int i,j;
        i = 0;
        j = m-1;
        result = false;
        while(i<n && j>=0)
        {
            if(v[i][j] == target)
            {
                result = true;
                break;
            }
            else if(v[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}