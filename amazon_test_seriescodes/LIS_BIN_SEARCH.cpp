#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[],int n)
{
    int lis[n];
    lis[0]=1;
    int max_length = 1;
    for(int i=1;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j]+1)
            {
                lis[i] = lis[j]+1;
                if(max_length < lis[i])
                {
                    max_length = lis[i];
                }
            }
        }
    }
    return max_length;
}
int LIS_BinSearch(int arr[],int N)
{
    int dp[N+1];
    for(int i=1;i<=N;i++)   
    {
        dp[i] = INT_MAX;
    }
    dp[0] = INT_MIN;
    for(int i=0;i<N;i++)
    {
        int idx = upper_bound(dp,dp+N+1,arr[i])-dp;
        if(arr[i] > dp[idx-1] && arr[i] < dp[idx+1])
        {
            dp[idx] = arr[i];
        }
    }
    int ma = 0;
    for(int i=N;i>=0;i--)
    {
        if(dp[i] != INT_MAX)
        {
            ma = i;
            break;
        }
    }
    return ma;
}
int main()
{   
    int arr[] = {10,22,9,33,21,50,41,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("LIS for array arr is:%d\n",LIS(arr,n));
    printf("LIS for array is:%d\n",LIS_BinSearch(arr,n));
    return 0;
}
