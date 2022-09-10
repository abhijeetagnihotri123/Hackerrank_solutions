#include <bits/stdc++.h>

using namespace std;

void test1()
{
    list<int>l{1,2,3,7,5,11,31,43,24};
    auto it = find(l.begin(),l.end(),7);
    if(it != l.end())
    {
        l.emplace(it,99);
    }
    for(const auto &it : l)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    test1();
    return 0;
}