#include <bits/stdc++.h>
using namespace std;

int LargestAreaRectangle(vector<int>&);

int main()
{       
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<LargestAreaRectangle(a);
    return 0;
}
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