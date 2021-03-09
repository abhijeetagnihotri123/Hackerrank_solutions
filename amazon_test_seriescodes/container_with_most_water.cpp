#include<iostream>
using namespace std;
long long maxArea(long long A[], int len);

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
    return 0;
}
long long maxArea(long long A[], int len)
{
    long long m1 = 0;
    int i = 0;
    int j = len-1;
    while(i<j)
    {
        long long m = min(A[i],A[j]);
        m1 = max(m1,m * (j-i));
        if(A[i] < A[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return m1;
}