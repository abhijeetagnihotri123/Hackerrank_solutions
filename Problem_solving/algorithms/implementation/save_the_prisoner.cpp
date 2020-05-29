#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int N,M,S;
        cin>>N>>M>>S;
        int c=(M+S-2)%N+1;
        cout<<c<<endl;
    }
    return 0;
}

