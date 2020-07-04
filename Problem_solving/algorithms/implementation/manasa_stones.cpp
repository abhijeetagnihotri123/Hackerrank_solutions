#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> stones(int n,int a,int b)
{
    set<int>s;
    int sum;
    for(int i=0;i<n;i++)
    {
        sum = a * i + b * (n-i-1);
        s.insert(sum);
    }
    vector<int>result;
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        int p = *it;
        result.push_back(p);
    }
    return result;
}
int main()
{
    int T,n,a,b;
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b;
        vector<int>result = stones(n,a,b);
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;  
}