#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int closest_sum = -2147483648;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int x,s;
        for(int i=0;i<n;i++)
        {
            int l = i+1;
            int r = n-1;
            x = arr[i];
            while(l<r)
            {   
                s = x+arr[l]+arr[r];
                if(abs(s-target) < abs(closest_sum-target))
                {   
                    closest_sum = s;
                }
                else if(s > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return closest_sum;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}