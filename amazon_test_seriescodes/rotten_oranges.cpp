#include <bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return a<=b?a:b;
}
struct orange
{
    int x,y,time_frame,type;//whether rotten or fresh
};
int rotOranges(vector<vector<int>>&matrix,int r,int c)
{   
    orange temp;  
    int num_fresh_oranges = 0;
    int time;
    queue<orange>q;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(matrix[i][j] == 2)
            {
                temp.x=i;
                temp.y=j;
                temp.time_frame=0;
                temp.type=2;
                q.push(temp);
            }
            if(matrix[i][j] == 1)
            {
                num_fresh_oranges++;
            }
        }
    }
    orange current;
    while(q.empty() != 1)
    {
        current = q.front();
        int i = current.x;
        int j = current.y;
        if(i>=1)
        {
            if(matrix[i-1][j] == 1)
            {
                matrix[i-1][j]=2;
                temp.time_frame = current.time_frame+1;
                temp.x = i-1;
                temp.y = j;
                temp.type = 2;
                num_fresh_oranges--;
                q.push(temp);
            }
        }
        if(j>=1)
        {
            if(matrix[i][j-1] == 1)
            {
                matrix[i][j-1]=2;
                temp.time_frame = current.time_frame+1;
                temp.x = i;
                temp.y = j-1;
                temp.type = 2;
                num_fresh_oranges--;
                q.push(temp);
            }
        }
        if(i<r-1)
        {
            if(matrix[i+1][j] == 1)
            {
                matrix[i+1][j]=2;
                temp.time_frame = current.time_frame+1;
                temp.x = i+1;
                temp.y = j;
                temp.type = 2;
                num_fresh_oranges--;
                q.push(temp);
            }
        }
        if(j<c-1)
        {
            if(matrix[i][j+1] == 1)
            {
                matrix[i][j+1]=2;
                temp.time_frame = current.time_frame+1;
                temp.x = i;
                temp.y = j+1;
                temp.type = 2;
                num_fresh_oranges--;
                q.push(temp);
            }
        }
        if(q.size() == 1)
        {
            time = current.time_frame;
        }
        q.pop();
    }
    if(num_fresh_oranges>0)
    {
        return -1;
    }
    return time;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int>>Matrix(R,vector<int>(C,0));
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                cin>>Matrix[i][j];
            }
        }
        cout<<rotOranges(Matrix,R,C)<<endl;
    }
    return 0;
}