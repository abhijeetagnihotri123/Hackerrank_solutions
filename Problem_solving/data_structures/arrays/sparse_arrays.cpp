#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
        int N;
        cin>>N;
        vector<string>a(N);
    for(int i(0);i<N;i++)
    {
       cin>>a[i];
    }
    int q;
    cin>>q;
    for(int i(0);i<q;i++)
    {   
        string temp="";
        cin>>temp;
        string t="";
        int c=0;
        for(int j(0);j<N;j++)
        {   
            if(a[j].compare(temp) == 0)
            {
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}

