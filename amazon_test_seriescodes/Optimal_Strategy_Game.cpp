#include <bits/stdc++.h>
using namespace std;

long long maximumAmount(int a[],int n)
{   
    int mat[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>j)
            {
                mat[i][j]=0;
            }
            else if(i==j)
            {
                mat[i][j] = a[i];
            }
        }
    }
    int i=0,j;
    for(i=0;i<n-1;i++)
    {
        mat[i][i+1] = max(a[i],a[i+1]);
    }
    i = 0;
    j = 2;
    while(i<n && j<n){
	        int r = i;
	        int c = j;
	        while(i<n && j<n){
	            mat[i][j] = max(a[j]+min(mat[i+1][j-1],mat[i][j-2]),a[i]+min(mat[i+2][j],mat[i+1][j-1]));
	            i++;j++;
	        }
	        i = 0;
	        j = c + 1;
	    }
    return mat[0][n-1];
}
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}