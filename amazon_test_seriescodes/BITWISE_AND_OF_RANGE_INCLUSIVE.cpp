#include <iostream>
using namespace std;
int rangeBitwiseAnd(int,int);
int main()
{   
    int L,R;
    cin>>L>>R;
    cout<<rangeBitwiseAnd(L,R)<<endl;
    return 0;
}
int rangeBitwiseAnd(int L,int R)
{
    int s = 1;
    while(L != R)
    {
        L = L>>1;
        R = R>>1;
        s = s<<1;
    }
    return (L*s);
}
