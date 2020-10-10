#include <bits/stdc++.h>
using namespace std;
 
// solution structure
struct Interval
{
    int buy;
    int sell;
};
void stockBuySell(int[],int);
int main()
{
    int price[10000],n,i,T;
    
    scanf("%d",&T);
    
    while(T--){
        
        scanf("%d",&n);
    
        for(i=0;i<n;i++)
            scanf("%d",&price[i]);
        // fucntion call
        stockBuySell(price, n);
        cout<<endl;
    }
    return 0;
}
void stockBuySell(int price[], int n)
{
    if(n==1)
    {
        cout<<"No Profit";
        return;
    }
    else
    {
        int i=0;
        int c=0;
        int buy,sell;
        while(i<n-1)
        {
            while(i<n-1 && price[i]>=price[i+1])
            {
                i++;
            }
            if(i == n-1)
            {
                break;
            }
            cout<<"("<<i<<" ";
            while(i<n-1 && price[i]<=price[i+1])
            {
                i++;
                c++;
            }
            cout<<i<<") ";
        }
        if(c==0)
        {
            cout<<"No Profit";
        }   
    }
}