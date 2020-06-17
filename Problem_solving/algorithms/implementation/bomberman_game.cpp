#include <iostream>
using namespace std;
bool grid1[202][202];
bool grid2[202][202];
char S[202][202];
int main()
{   
    int r,c,n;
    cin>>r>>c>>n;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>S[i][j];
        }
    }
    if(n==1)
    {
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cout<<S[i][j];
            }
            cout<<endl;
        }
        return 0;
    }
    else if(n%2==0)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<'O';
            }
            cout<<endl;
        }
        return 0;
    }
    else
    {
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(S[i][j]=='O')
                {
                    grid1[i][j]=grid1[i-1][j]=grid1[i+1][j]=grid1[i][j-1]=grid1[i][j+1]=true;
                }
            }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(!grid1[i][j])
                {
                    grid2[i][j]=grid2[i-1][j]=grid2[i+1][j]=grid2[i][j-1]=grid2[i][j+1]=true;
                }
            }
        }
        if(n%4==3)
        {
            for(int i=1;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    if(grid1[i][j])
                    {
                        cout<<'.';
                    }
                    else
                    {
                        cout<<'O';
                    }
                }
                cout<<endl;
            }
        }
        if(n%4==1)
        {
            for(int i=1;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    if(grid2[i][j])
                    {
                        cout<<'.';
                    }
                    else
                    {
                        cout<<'O';
                    }
                    
                }
                cout<<endl;
            }
        }
    }
    return 0;   
}