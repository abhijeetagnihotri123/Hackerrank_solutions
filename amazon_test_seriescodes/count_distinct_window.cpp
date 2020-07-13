#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k;
    cin>>n>>k;
    int *a;
    a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    deque<int>q;
    map<int,int>m;
    int i=0;
    for(i=0;i<k;i++)
    {
        m[a[i]]++;
        q.push_back(a[i]);
    }
    cout<<m.size()<<" ";
    for(i=k;i<n;i++)
    {
        int current = q.front();
        q.pop_front();
        m[current]--;
        m[a[i]]++;
        q.push_back(a[i]);
        if(m[current] == 0)
        {
            m.erase(current);
        }
        cout<<m.size()<<" ";
    }
    delete(a);
    return 0;
}