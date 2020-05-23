#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    priority_queue<double,vector<double>,greater<double>>minheap;
    priority_queue<double>maxheap;
    vector<double>medians;
    double median=0.0;
    double k;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(k>median)
        {
            minheap.push(k);
        }
        else
        {
            maxheap.push(k);
        }
        if(minheap.size()>maxheap.size()+1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size()>maxheap.size())
        {
            median=minheap.top()/1.0;
            medians.push_back(median);
        }
        else if(maxheap.size()>minheap.size())
        {
            median=maxheap.top()/1.0;
            medians.push_back(median);
        }
        else if(minheap.size()==maxheap.size())
        {
            median=(minheap.top()+maxheap.top())/2.0;
            medians.push_back(median);
        }
    }
    for(int i=0;i<medians.size();i++)
    {
        printf("%0.1f\n",medians[i]);
    }
    return 0;
}
