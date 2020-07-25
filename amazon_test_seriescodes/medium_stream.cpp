#include <bits/stdc++.h>
using namespace std;

priority_queue<int>max_heap; //max_heap_heap to store min_heap elements;
priority_queue<int,vector<int>,greater<int>>min_heap; //min_heap heap for max_heap elements
void insertHeap(int &);
void balanceHeaps(void);
double getMedian(void);
int main()
{       

    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        insertHeap(k);
        cout<<floor(getMedian())<<endl;
    }
    return 0;
}
void insertHeap(int &x)
{
    if(max_heap.empty() && min_heap.empty())
    {
        max_heap.push(x);
    }
    if(x > max_heap.top())
    {
        min_heap.push(x);
        int s1,s2;
        s1 = max_heap.size();
        s2 = min_heap.size();
        if(abs(s1-s2)>1)
        {
            balanceHeaps();
        }
    }
    if(x < max_heap.top())
    {
        max_heap.push(x);
        int s1 = max_heap.size();
        int s2 = min_heap.size();
        if(abs(s1-s2)>1)
        {
            balanceHeaps();
        }
    }
}
void balanceHeaps()
{
    if(max_heap.size()>min_heap.size())
    {
        int t = max_heap.top();
        max_heap.pop();
        min_heap.push(t);
    }
    else
    {
        int t = min_heap.top();
        min_heap.pop();
        max_heap.push(t);
    }
}
double getMedian()
{   
    double median;
    if(max_heap.size() == (min_heap.size()+1))
    {
        median = max_heap.top();
    }
    else if(min_heap.size() == (max_heap.size()+1))
    {
        median = min_heap.top();
    }
    else
    {
        int t1 = max_heap.top();
        int t2 = min_heap.top();
        median = (t1+t2)/(2.0);
    }
    return median;
}