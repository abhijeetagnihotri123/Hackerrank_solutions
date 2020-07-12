// #include <bits/stdc++.h>
// using namespace std;
// #define N 100001

// int a[N];
// int b[N];
// void compute_cycle(int k,long long int &n)
// {   
//     long long int offset;
//     for(long long int i=0;i<n;i++)
//     {   
//         offset = (1<<k);
//         b[i] = (a[i]^a[(i+offset)%n]);
//     }
//     for(long long int i=0;i<n;i++)
//     {
//         a[i]=b[i];
//     }
// }
// int main()
// {   
//     long long int m,aux,n;
//     cin>>n>>m;
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     int max_cycles = 60;
//     m--;
//     for(int i=0;i<max_cycles;i++)
//     {
//         aux = (1<<i);
//         if(m > aux)
//         {
//             compute_cycle(i,n);
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define N 111111
int a[N];
int b[N];
int n;

void move(int k) {
    // compute the 2^k'th row
    for (int i = 0; i < n; i++) b[i] = a[i] ^ a[(i + (1LL << k)) % n];
    
    // copy back to 'a'
    for (int i = 0; i < n; i++) a[i] = b[i];
}
int main() {
    // take the input
    long long m;
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    
    // compute the answers
    m--;
    for (int k = 0; k < 60; k++) {
        if (m & (1LL << k)) move(k);
    }
    
    // print the answers
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}