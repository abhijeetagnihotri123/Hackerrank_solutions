#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int r=N;
        int c=0;
        
        while(r>0)
        {   
            if(r%10!=0&&N%(r%10)==0){c++;}
            r=r/10;
        }
        cout<<c<<endl;
    }
    return 0;
}

