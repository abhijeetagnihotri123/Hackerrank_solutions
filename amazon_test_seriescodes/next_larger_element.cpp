#include <bits/stdc++.h>
using namespace std;

vector <long long> nextLargerElement(long long arr[], int n){
    
    stack<long long>s;
    vector<long long>result(n);
    map<int,int>m;
    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {   
        m[arr[i]]=i;
        if(s.empty())
        {
            s.push(arr[i]);
            continue;
        }

        while(!s.empty() && s.top() < arr[i])
        {
            int t = s.top();
            result[m[t]]=arr[i];
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {   
        int x = -1;
        int t = s.top();
        result[m[t]]=-1;
        s.pop();
    }
    return result;
}

int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector <long long> arr = nextLargerElement(a,n);
        for(long long x : arr)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}