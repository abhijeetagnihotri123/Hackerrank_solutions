#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&);
int main()
{   
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<maxProfit(p)<<endl;
    return 0;
}
int maxProfit(vector<int> &p)
{
    int n = p.size();
    int max_profit = 0;
    if(n < 2)
    {
        max_profit = 0;
    }
    else if(n == 2)
    {
        max_profit = p[1]>=p[0]?p[1]-p[0]:0;
    }
    else
    {
        int i=0;
        int min_price = 2147483647;
        for(i=0;i<n;i++)
        {
            if(min_price > p[i])
            {
                min_price = p[i];
            }
            if((p[i] - min_price) > max_profit)
            {
                max_profit = p[i] - min_price;
            }
        }
    }
    return max_profit;
}