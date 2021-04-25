#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        vector<vector<int>>res;
        set<vector<int>>S;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int l,r;
        vector<int>aux(4);
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                l = j+1;
                r = n-1;
                while(l<r)
                {
                    int s = arr[i]+arr[j]+arr[l]+arr[r];
                    if(s == k)
                    {
                        aux[0] = arr[i];
                        aux[1] = arr[j];
                        aux[2] = arr[l];
                        aux[3] = arr[r];
                        S.insert(aux);
                        l++;
                        r--;
                    }
                    else if(s < k)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        for(auto x : S)
        {
            res.push_back(x);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}