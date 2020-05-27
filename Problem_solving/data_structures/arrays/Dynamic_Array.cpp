#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,Q;
    cin>>N>>Q;
        vector<vector<int>>a(N);
        int q,x,y; 
        int lastanswer=0;
        for(int i(0);i<Q;i++)
        {
               cin>>q>>x>>y;
                int r=0;
                if(q==1)
               {
                   r=((x^lastanswer)%N);
                   a[r].push_back(y);
               }
                else if(q==2)
                {   
                    r=((x^lastanswer)%N);
                    int size=a[r].size();
                    int z=y%size;
                    lastanswer=a[r][z];   
                    cout<<lastanswer<<endl;
                }
        }
    return 0;
}

