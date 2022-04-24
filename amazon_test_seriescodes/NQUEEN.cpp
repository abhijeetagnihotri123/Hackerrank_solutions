#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool check_row(int row,int col,int n,vector<vector<int>>&visited)
    {   
        int i = row;
        int j = col;
        j--;
        while(j>=0)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            j--;
        }
        j = col+1;
        while(j<n)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            j++;
        }
        return true;
    }
    bool check_col(int row,int col,int n,vector<vector<int>>&visited)
    {   
        int i = row;
        int j = col;
        i--;
        while(i>=0)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i--;
        }
        i = row+1;
        while(i<n)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i++;
        }
        return true;
    }
    bool check_diagonal(int row,int col,int n,vector<vector<int>>&visited)
    {
        int i,j;
        i = row;
        j = col;
        i--;
        j--;
        while(i>=0 && j>=0)
        {
            if(visited[i][j] == 1)
            {   
                return false;
            }
            i--;
            j--;
        }
        i = row+1;
        j = col+1;
        while(i<n && j<n)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i++;
            j++;
        }
        i = row+1;
        j = col-1;
        while(i<n && j>=0)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i++;
            j--;
        }
        i = row-1;
        j = col+1;
        while(i>=0 && j<n)
        {
            if(visited[i][j] == 1)
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    bool check(int row,int col,int n,vector<vector<int>>&visited)
    {
        bool b1 = check_row(row,col,n,visited);
        bool b2 = check_col(row,col,n,visited);
        bool b3 = check_diagonal(row,col,n,visited);
        return b1 && b2 && b3;
    }
    void solve(int row,int &n,set<vector<int>>&s,vector<vector<int>>&visited,vector<int>&temp)
    {
        if(row == n)
        {
            s.insert(temp);
            return;
        }
        else
        {
            for(int col = 0;col < n;col++)
            {
                if(check(row,col,n,visited))
                {
                    visited[row][col] = 1;
                    temp[col] = row+1;
                    solve(row+1,n,s,visited,temp);
                    visited[row][col] = 0;
                    temp[col] = -1;
                }
            }
        }
    }
    vector<vector<int>> nQueen(int n) 
    {   
        vector<vector<int>>visited(n,vector<int>(n,0));
        set<vector<int>>s;
        vector<int>temp(n,-1);
        solve(0,n,s,visited,temp);
        vector<vector<int>>res;
        for(auto it : s)
        {
            res.push_back(it);
        }
        return res;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
} 