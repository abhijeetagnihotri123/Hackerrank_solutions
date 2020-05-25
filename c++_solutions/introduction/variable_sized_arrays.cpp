#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q;
    cin>>n;
    cin>>q;
    vector<vector<int>>a(n);
        for(int i=0;i<n;i++){
            int k=0;
            cin>>k;
            for(int j=0;j<k;j++){
                int val=0;
                cin>>val;
                a[i].push_back(val);
            }
        }
    for(int i=0;i<q;i++){
        int x=0;
        int y=0;
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
        return 0;
}
