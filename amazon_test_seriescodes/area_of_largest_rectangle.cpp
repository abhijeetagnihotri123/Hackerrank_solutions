#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


int LargestAreaRectangle(vector<int>&a)
{
    stack<int>s;
    int i=0;
    int area;
    int max_area=0;
    int n = a.size();
    while(i<n)
    {
        if(s.empty() || a[s.top()]<=a[i])
        {
            s.push(i);
            i++;
        }   
        else
        {
            int top = s.top();
            s.pop();
            if(s.empty())
            {
                area = a[top] * i;
            }
            else
            {
                area = a[top] * (i-s.top()-1);
            }
            if(area > max_area)
            {
                max_area = area;
            }
        }
    }
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        if(s.empty())
        {
            area = a[top] * i;
        }
        else
        {
            area = a[top] * (i-s.top()-1);
        }
        if(area > max_area)
        {
            max_area = area;
        }
    }
    return max_area;
}
/*
1 0 0 1 1 1
1 0 1 1 0 1
0 1 1 1 1 1
0 0 1 1 1 1
*/
int findMaxArea(int N,int M,int A[SIZE][SIZE])
{   
    vector<int>hist(M,0);
    int histogram_area,max_area;
    max_area = 0;
    for(int i=0;i<M;i++)
    {
        hist[i] += A[0][i];
    }
    histogram_area = LargestAreaRectangle(hist);
    for(int i=1;i<N;i++)
    {   

        histogram_area = LargestAreaRectangle(hist);
        for(int j=0;j<M;j++)
        {
            if(A[i][j] == 0)
            {
                hist[j]=0;
            }
            else
            {
                hist[j] += A[i][j];
            }
        }
        if(max_area < histogram_area)
        {
            max_area = histogram_area;
        }
    }
    histogram_area = LargestAreaRectangle(hist);
    if(histogram_area > max_area)
    {
        max_area = histogram_area;
    }
    return max_area;
}

int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int g[SIZE][SIZE];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>g[i][j];
            }
        }
        cout<<findMaxArea(n,m,g)<<endl;
    }
    return 0;
}