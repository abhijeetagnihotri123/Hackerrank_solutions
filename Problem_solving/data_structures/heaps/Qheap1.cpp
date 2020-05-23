#include <bits/stdc++.h>
using namespace std;


int main() {
    set<int>PQ;
    int Q;
    cin>>Q;
    int v;
    int x;
    while(Q--)
    {
        cin>>v;
        if(v==1)
        {
            cin>>x;
            PQ.insert(x);
        }
        else if(v==2)
        {   
            cin>>x;
            PQ.erase(x);
        }
        else if(v==3)
        {
            cout<<*(PQ.begin());
            cout<<endl;
        }
    }
    return 0;
}
