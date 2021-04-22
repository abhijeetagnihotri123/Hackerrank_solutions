#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool issafe(vector<vector<int>>&m,int n,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=n || m[i][j] == 0)
        {
            return false;
        }
        return true;
    }
    void findPathUtil(vector<vector<int>>&m,int n,int i,int j,string str,vector<string>&s)
    {
        if(i<0 || i>=n || j<0 || j>=n || m[i][j] == 0)
        {
            return;
        }
        else
        {
            if(i == n-1 && j == n-1)
            {
                s.push_back(str);
                return;
            }
            m[i][j] = 0;
            if(issafe(m,n,i+1,j))
            {
                str.push_back('D');
                findPathUtil(m,n,i+1,j,str,s);
                str.pop_back();
            }
            if(issafe(m,n,i,j+1))
            {
                str.push_back('R');
                findPathUtil(m,n,i,j+1,str,s);
                str.pop_back();
            }
            if(issafe(m,n,i-1,j))
            {
                str.push_back('U');
                findPathUtil(m,n,i-1,j,str,s);
                str.pop_back();
            }
            if(issafe(m,n,i,j-1))
            {
                str.push_back('L');
                findPathUtil(m,n,i,j-1,str,s);
                str.pop_back();
            }
            m[i][j] = 1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        string str = "";
        vector<string>res;
        findPathUtil(m,n,0,0,str,res);
        sort(res.begin(),res.end());
        return res;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} 