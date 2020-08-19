#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}

int maxLen(int arr[],int N)
{
    unordered_map<int,int>m;
    int longest_length = 0;
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        if(arr[i] == 0)
        {
            sum -= 1;
        }
        else
        {
            sum += 1;
        }
        if(sum == 0)
        {
            if(longest_length<(i+1))
            {
                longest_length=i+1;
            }
        }
        else if(m.find(sum) != m.end())
        {
            if(longest_length < (i-m[sum]))
            {
                longest_length = i - m[sum];
            }
        }
        else
        {
            m[sum] = i;
        }
    }
    return longest_length;
}