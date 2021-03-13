#include <bits/stdc++.h>
using namespace std;
void sieve_of_eratosthenes(int&,int&);
int main()
{   
    int c;
    int n;
    cin>>n;
    sieve_of_eratosthenes(n,c);
    cout<<c;
    return 0;
}
void sieve_of_eratosthenes(int &n,int &c)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    c = 0;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p]) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {    
        if (prime[p])
        {
            c++;
        }
    }
}
