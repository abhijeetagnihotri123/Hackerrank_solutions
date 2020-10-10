#include <bits/stdc++.h>
using namespace std;

int findMissing(int arr[],int n)
{   
    if(n == 1)
    {
        return 1;
    }
    set<int>s;
    int smallest_positive = INT_MAX;
    bool negative = false;
    for(int i=0;i<n;i++)
    {   
        if(arr[i] >=0)
        {       
            if(smallest_positive > arr[i])
            {
                smallest_positive = arr[i];
            }
            s.insert(arr[i]);
        }
        else 
        {
            negative = true;
        }
    }
    if(negative)
    {
        int i = 0;
        if(s.find(i) == s.end())
        {
            s.insert(i);
            smallest_positive = 0;
        }
    }   
    while(s.find(smallest_positive) != s.end())
    {
        smallest_positive++;
    }
    return smallest_positive;
}
int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];
        
        cout<<findMissing(arr, n)<<endl;
    }
    return 0; 
}