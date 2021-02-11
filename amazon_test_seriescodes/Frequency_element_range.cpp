// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
void frequencycount(vector<int>& arr,int n);

// your code will be pasted here

void frequencycount(vector<int>& arr,int n)
{ 
    for(int i=0;i<n;i++)
    {
        arr[i] -= 1;
    }
    for(int i=0;i<n;i++)
    {
        arr[(arr[i])%n]+=n;
    }
    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i]/n;
    }
}

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int n;
	    //size of array
	    cin >> n; 
	    
	    vector<int> arr(n,0);
	    
	    //adding elements to the vector
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; 
	    }

        //calling frequncycount() function
		frequencycount(arr,n); 
		
		//printing array elements
	    for (int i =0; i<n; i++) 
			cout<<arr[i]<<" ";
	    cout<<endl;
	}	
	return 0; 
}