#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
int check_zeroes(vector<long long int>&nums,map<long long int,bool>&m,int &n,long long int &p)
{   
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(nums[i] == 0)
        {
            m[i] = true;
            c++;
        }
        else
        {
            p *= nums[i];
        }
    }
    return c;
}
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    if(n == 1)// || n == 0)
    {   
        nums[0] = 1;
        return nums;
    }
    else if(n == 2)
    {
        nums[0] = nums[0] ^ nums[1];
        nums[1] = nums[0] ^ nums[1];
        nums[0] = nums[0] ^ nums[1];        
        return nums;
    }
    else
    {   
        map<long long int,bool>m;
        long long int p = 1;
        int c  = check_zeroes(nums,m,n,p);
        if(c == n)
        {
            return nums;
        }
        else if(c == 0)
        {
            for(int i=0;i<n;i++)
            {
                nums[i] = p/nums[i];
            }
        }
        else
        {
            if(c == 1)
            {
                for(int i(0);i<n;i++)
                {
                    if(nums[i] == 0)
                    {
                        nums[i] = p;
                    }
                    else
                    {
                        nums[i] = 0;
                    }
                }
            }
            else
            {
                for(int i(0);i<n;i++)
                {
                    nums[i] = 0;   
                }
            }
        }
        return nums;
    } 
}
