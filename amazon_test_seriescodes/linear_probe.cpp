#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,N,HashSize;
    //cin>>T;
    //while(T--)
    {
        cin>>HashSize>>N;
        vector<int>arr(N);
        vector<int>hash_table(HashSize,-1);
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<N;i++)
        {
            int index = arr[i] % HashSize;
            if(hash_table[index] == -1)
            {
                hash_table[index] = arr[i];
            }
            else
            {
                int c = 1;
                int index = (c+arr[i])%HashSize;
                while(hash_table[index] != -1 && c!=HashSize)
                {
                    c++;
                    index = (c+arr[i])%HashSize;
                }
                hash_table[index] = arr[i];
            }
        }
        for(int i=0;i<HashSize;i++)
        {
            cout<<hash_table[i]<<" ";
        }
    }
}