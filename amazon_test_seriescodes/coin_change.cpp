#include <bits/stdc++.h>
using namespace std;

long long result = INT_MIN;
long long minimumnumbercoins(int S[],int m,int n)
{
    if (n == 0) 
        return 1; 
      
    if (n < 0) 
        return 0; 
  
    if (m <=0 && n >= 1) 
        return 0; 
    
    return minimumnumbercoins(S,m-1,n)+minimumnumbercoins(S,m,n-S[m-1]);
}
long long dynamicnumbercoins(int S[],int m,int n)
{

}
int main()
{   
    int T;
    cin>>T;
    while(T--)
    {
        int X,N;
        cin>>X>>N;
        int coins[N];
        for(int i=0;i<N;i++)
        {
            cin>>coins[i];
        }
        result = minimumnumbercoins(coins,N,X);
        result = result == 0 ? -1 : result;
        cout<<result;
    }
    return 0;
}
