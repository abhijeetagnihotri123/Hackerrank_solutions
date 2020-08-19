#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
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
        vector<vector<int> > ans = fourSum(a, k);
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
vector<vector<int> > fourSum(vector<int> &a, int X) {

    vector<vector<int>>res;
    if(a.size() < 4)
    {
        return res;
    }
    int n = a.size();
    sort(a.begin(),a.end());
    int l,r;
    for (int i = 0; i < n - 3; i++)  
    {  
        for (int j = i+1; j < n - 2; j++)  
        {  
            l = j + 1;  
            r = n-1;   
            while (l < r)  
            {  
                if( a[i] + a[j] + a[l] + a[r] == X)  
                {  
                    vector<int>v(4);
                    v[0] = a[i];
                    v[1] = a[j];
                    v[2] = a[l];
                    v[3] = a[r];
                    res.push_back(v);  
                    l++; r--;  
                }  
                else if (a[i] + a[j] + a[l] + a[r] < X)  
                    l++;  
                else  
                    r--;  
            }  
        }  
    }
    return res;
}