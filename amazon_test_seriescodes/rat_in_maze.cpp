#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
bool check_path(int m[MAX][MAX],bool visited[MAX][MAX],int i,int j,int n)
{
    if(i>=n || j>=n || i<0 || j<0 || visited[i][j] ||m[i][j] == 0)
    {
        return false;
    }
    return true;
}
void extract_path(int m[MAX][MAX],bool visited[MAX][MAX],string &str,vector<string>&a,int i,int j,int n)
{
    if(i>=n || j>=n || i<0 || j<0 || visited[i][j] ||m[i][j] == 0)
    {
        return;
    }
    if(i==n-1 && j==n-1)
    {
        a.push_back(str);
        return;
    }
    visited[i][j] = true;
    if(check_path(m,visited,i+1,j,n))
    {
        str.push_back('D');
        extract_path(m,visited,str,a,i+1,j,n);
        str.pop_back();
    }
    if(check_path(m,visited,i,j+1,n))
    {
        str.push_back('R');
        extract_path(m,visited,str,a,i,j+1,n);
        str.pop_back();
    }
    if(check_path(m,visited,i-1,j,n))
    {
        str.push_back('U');
        extract_path(m,visited,str,a,i-1,j,n);
        str.pop_back();
    }
    if(check_path(m,visited,i,j-1,n))
    {
        str.push_back('L');
        extract_path(m,visited,str,a,i,j-1,n);
        str.pop_back();
    }
    visited[i][j] = false;
}
vector<string> printPath(int m[MAX][MAX],int n)
{   
    vector<string>a;
    if(m[n-1][n-1] == 0)
    {
        return a;
    }
    else
    {
        string str="";
        bool visited[MAX][MAX] = {{false,false,false,false,false},{false,false,false,false,false},{false,false,false,false,false},{false,false,false,false,false},{false,false,false,false,false}};
        extract_path(m,visited,str,a,0,0,n);
    }
    return a;
}