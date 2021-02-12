#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// function to find the triplet which sum to x
// arr[] : The input Array
// N : Size of the Array
// X : Sum which you need to search for 

bool find3Numbers(int arr[], int N, int X)
{
    bool flag=false;
    sort(arr,arr+N);
    int l,r;
    for(int i=0;i<N-2;i++)
    {
        l = i+1;
        r = N-1;
        while(l<r)
        {
            if((arr[i]+arr[l]+arr[r]) == X)
            {
                flag = true;
                break;
            }
            else if((arr[i]+arr[l]+arr[r]) > X)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        if(flag)
        {
            break;
        }
    }
    return flag;
}


// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
        cout <<  find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends