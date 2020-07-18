#include <iostream>
#include <deque>

using namespace std;

int main()
{   
    int T,n,k;
    cin>>T;
    while(T--)
    {   
        cin>>n>>k;
        int *a;
        a = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        deque<int>Q;
        int i; 
        for (i = 0; i < k; ++i) 
        { 
            while ((!Q.empty()) && a[i] >= a[Q.back()]) 
            {
                Q.pop_back();
            }  
            Q.push_back(i); 
        }
        for(;i<n;i++)
        {
            cout<<a[Q.front()]<<" ";
            while(!Q.empty() && Q.front()<=(i-k))
            {
                Q.pop_front();
            }
            while(!Q.empty() && a[i] >= a[Q.back()])
            {
                Q.pop_back();
            }
            Q.push_back(i);
        }
        cout<<a[Q.front()]<<endl;
        delete(a);
    }
    return 0;
}