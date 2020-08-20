#include<bits/stdc++.h>

using namespace std;

int minimumJumps(int[], int);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}

int minimumJumps(int a[],int n)
{
    int reachable = 0;
    int hops = 0;
    int stepsPossible = a[0];
    for(int i=0;i<n;i++)
    {
        if(i == n-1)
        {
            break;
        }
        reachable = max(reachable,i+a[i]);
        stepsPossible--;
        if(stepsPossible == 0)
        {
            hops++;
            if(i>=reachable)
            {
                hops = -1;
                break;
            }
            stepsPossible = reachable - i;
        }
    }
    return hops;
}