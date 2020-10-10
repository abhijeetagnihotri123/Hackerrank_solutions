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
int LIS_BinSearch(int arr[],int n)
{
    vector<int>parent(n,0);
    vector<int>increasingSub(n,0);
    int length = 0;
    for(int i=0;i<n;i++)
    {
        int low = 1;
        int high = n;
        while(low <= high)
        {
            int mid = ceil((low+high)/2);
            if(arr[increasingSub[mid]] < arr[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        int pos = low;
        parent[i] = increasingSub[i];
        increasingSub[pos] = i;
        if(pos > length)
        {
            length = pos; 
        }
    }
    return length;
}
int main()
{   
    int arr[] = {10,22,9,33,21,50,41,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("LIS for array arr is:%d\n",LIS(arr,n));
    printf("LIS for array is:%d\n",LIS_BinSearch(arr,n));
    return 0;
}