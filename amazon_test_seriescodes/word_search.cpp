#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool WordSearch(vector<vector<char>>&,string&);
int main()
{   
    int n,m;
    cin>>n>>m;
    vector<vector<char>>board(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    string str;
    cin>>str;
    cout<<WordSearch(board,str);
    return 0;
}
bool search_aux(vector<vector<char>>&board,int i,int j,int n,int m,int size,int index,string word)
{   
    if(i<0 || j<0)
    {
        return false;
    }
    else if(i>=n || j>=m)
    {
        return false;
    }
    else if(word[index] != board[i][j])
    {
        return false;
    }
    else if(size == 1 && board[i][j] == word[index])
    {
        return true;
    }
    else if(size == 1 && board[i][j] != board[i][j])
    {
        return false;
    }
    else 
    {
        bool b1,b2,b3,b4;
        b1 = search_aux(board,i+1,j,n,m,size-1,index+1,word);
        b2 = search_aux(board,i,j+1,n,m,size-1,index+1,word);
        b3 = search_aux(board,i-1,j,n,m,size-1,index+1,word);
        b4 = search_aux(board,i,j-1,n,m,size-1,index+1,word);
        return (b1 || b2 || b3 || b4);
    }
}
bool WordSearch(vector<vector<char>>&board,string &word)
{
    int n = board.size();
    int m = board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j] == word[0])
            {
                if(search_aux(board,i,j,n,m,word.size(),0,word))
                {
                    return true;
                }
            }
        }
    }
    return false;
}