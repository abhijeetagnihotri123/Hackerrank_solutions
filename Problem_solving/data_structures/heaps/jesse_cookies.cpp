#include <bits/stdc++.h>
using namespace std;
int main()
{   
    priority_queue<int,vector<int>,greater<int>>pq;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int aux;
        cin>>aux;
        pq.push(aux);
    }
    int c=0;
    int sum=0;
    int v1,v2;
    while(1)
    {
        if(pq.size()==1)
        {
            break;
        }
        v1=pq.top();
        pq.pop();
        if(v1>=k)
        {
            break;
        }
        v2=pq.top();
        pq.pop();
        sum=v1+2*v2;
        pq.push(sum);
        c++;
    }
    if(pq.size()==1 && pq.top() < k)
    {
        cout<<-1;
    }
    else
    {
        cout<<c;
    }
    
    return 0;
}
