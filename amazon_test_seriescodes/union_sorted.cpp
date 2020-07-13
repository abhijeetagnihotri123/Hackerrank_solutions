#include <bits/stdc++.h>
using namespace std;
vector<int> findUnion(int a[], int b[], int n, int m)
{
    vector<int>result;
    map<int,bool>m;
    int i,j;
    i=j=0;
    while(i<n && j<m)
    {
        if(B[i]<=C[j])
        {
            A[k]=B[i];
            i++;
        }
        else
        {
            A[k]=C[j];
            j++;
        }
        k++;
    }
    while(i<n)
    {
        A[k]=B[i];
        i++;
        k++;
    }
    while(j<m)
    {
        A[k]=C[j];
        j++;
        k++;
    }
}
int main()
{
    int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    vector<int> ans = findUnion(arr1,arr2, N, M);
	    for(int i: ans)
            {cout<<i<<' ';}
	    cout << endl;    
	}
	
	return 0;
}