#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int T;
    cin>>T;
    while(T--)
    {
    int R,C,r,c;
    cin>>R>>C;
    vector<string>grid;
    vector<string>subgrid;
    string str;
    for(int i=0;i<R;i++)
    {
        cin>>str;
        grid.push_back(str);
    }
    str="";
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        cin>>str;
        subgrid.push_back(str);
    }
    if(r>R || c>C)
    {
        cout<<"NO"<<endl;
    }
    else
    {   
        int i,j,x,y,count,flag=0;
        bool result;
        for(i=0;i<R;i++)
        {   
            result=false;
            for(j=0;j<C;j++)
            {
                if(grid[i][j]==subgrid[0][0])
                {   
                    result=true;
                    for(x=0;x<r;x++)
                    {
                        for(y=0;y<c;y++)
                        {   
                            result=result&&(grid[i+x][j+y]==subgrid[x][y]);
                        }
                    }
                    if(result==true)
                    {   
                        flag=1;
                        break;
                    }    
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        if(result)
        {
            cout<<"YES"<<endl;
        }    
        else
        {
            cout<<"NO"<<endl;
        }
    }
    }
    return 0;
}


