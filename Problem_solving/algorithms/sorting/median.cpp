#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
        int n;
        cin>>n;
        vector<int>A(n);   
        for(int i(0);i<n;i++){cin>>A[i];}
        sort(A.begin(),A.end());
        if(n%2!=0){cout<<A[(n-1)/2];}
        else
        {
            float m=0.0;
            int k=(n-1)/2;
            m=(float)(A[k]+A[k+1])/2.0;
            cout<<m;
        }
    return 0;
}

