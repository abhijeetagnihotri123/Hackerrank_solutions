#include <bits/stdc++.h>
using namespace std;
void partition(int *,int,int);
int main()
{   
    int n;
    cin>>n;
    vector<int>less;
    vector<int>more;
    int k;
    int pivot;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cin>>pivot;
        }
        else if(i!=0)
        {   
            cin>>k;
            if(pivot>=k)
            {
                less.push_back(k);
            }
            else
            {
                more.push_back(k);
            }
        }
    }
    for(int i=0;i<less.size();i++)
    {
        cout<<less[i]<<" ";
    }
    cout<<pivot<<" ";
    for(int i=0;i<more.size();i++)
    {
        cout<<more[i]<<" ";
    }
    less.clear();
    more.clear();
    return 0;
}
