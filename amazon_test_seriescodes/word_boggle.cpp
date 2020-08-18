#include <bits/stdc++.h>
using namespace std;



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
        bool b5 = DFS(board,i-1,j-1,count+1,word);
        bool b6 = DFS(board,i-1,j+1,count+1,word);
        bool b7 = DFS(board,i+1,j-1,count+1,word);
        bool b8 = DFS(board,i+1,j+1,count+1,word);
        board[i][j] = temp;
        return (b1 || b2 || b3 || b4 || b5 || b6 || b7 || b8);
    }
}
vector<string> boggle(vector<vector<char> >& board,vector<string>& dictionary) {
    vector<string>result;
    for(int k=0;k<dictionary.size();k++)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j] == dictionary[k][0] && DFS(board,i,j,0,dictionary[k]))// && !visited[dictionary[k]] && !v1[k])
                {   
                    result.push_back(dictionary[k]);  
                    dictionary[k]="";
                }
            
            }
        }
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dictionary;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int r, c;
        cin >> r >> c;
        vector<vector<char> > board(r);
        for (int i = 0; i < r; i++) {
            board[i].resize(c);
            for (int j = 0; j < c; j++) cin >> board[i][j];
        }
        vector<string> output = boggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}