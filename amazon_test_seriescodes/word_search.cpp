#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool WordSearch(vector<vector<char>>&,string&);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<char> > board(m);
        for (int i = 0; i < m; i++) {
            board[i].resize(n);
            for (int j = 0; j < n; j++) cin >> board[i][j];
        }
        string str;
        cin >> str;
        cout << WordSearch(board, str) << endl;
    }
    return 0;
}
bool DFS(vector<vector<char>>&board,int i,int j,int count,string &word)
{   
    if(count == word.length())
    {
        return true;
    }
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[count])
    {
        return false;
    }
    else
    {   
        char temp = board[i][j];
        board[i][j] = ' ';
        bool b1 = DFS(board,i-1,j,count+1,word);
        bool b2 = DFS(board,i+1,j,count+1,word);
        bool b3 = DFS(board,i,j-1,count+1,word);
        bool b4 = DFS(board,i,j+1,count+1,word);
        board[i][j] = temp;
        return (b1 || b2 || b3 || b4);
    }
}
bool WordSearch(vector<vector<char>>&board,string &word)
{
    int n = board.size();
    int m = board[0].size();
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==word[0] && DFS(board,i,j,0,word))
            {   
                flag = true;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }
    return flag;
}