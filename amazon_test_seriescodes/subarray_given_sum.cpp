#include <iostream>
using namespace std;
void subArraySum(int arr[],int n,int sum)
{
    int curr_sum = arr[0], start = 0, i; 
    for (i = 1; i <= n; i++) { 
        while (curr_sum > sum && start < i - 1) { 
            curr_sum = curr_sum - arr[start]; 
            start++; 
        } 
        if (curr_sum == sum) { 
            cout<< start+1 <<" "<< i;// - 1; 
            return; 
        }  
        if (i < n) 
            curr_sum = curr_sum + arr[i]; 
    } 
    cout << "-1"; 
    cout<<endl; 
}
int main()
{   
    int T,n,sum;
    cin>>T;
    while(T--)
    {
        cin>>n>>sum;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        subArraySum(a,n,sum);
    }
    return 0;
}