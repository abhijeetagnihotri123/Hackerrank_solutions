#include <bits/stdc++.h>
using namespace std;
int main()
{
    int magic0[3][3]={{8,1,6},{3,5,7},{4,9,2}};
    int magic1[3][3]={{6,1,8},{7,5,3},{2,9,4}};
    int magic2[3][3]={{4,3,8},{9,5,1},{2,7,6}};
    int magic3[3][3]={{2,7,6},{9,5,1},{4,3,8}};
    int magic4[3][3]={{2,9,4},{7,5,3},{6,1,8}};
    int magic5[3][3]={{4,9,2},{3,5,7},{8,1,6}};
    int magic6[3][3]={{6,7,2},{1,5,9},{8,3,4}};
    int magic7[3][3]={{8,3,4},{1,5,9},{6,7,2}};
    int s[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>s[i][j];
        }
    }
    vector<int>sum;
    int total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic0[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic1[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic2[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic3[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic4[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic5[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic6[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    total=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            total+=abs(magic7[i][j]-s[i][j]);
        }
    }
    sum.push_back(total);
    sort(sum.begin(),sum.end());

        cout<<sum[0];

    return 0;
}

