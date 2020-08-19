#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
int max(int a,int b)
{
    return a>=b?a:b;
}
int findLongestConseqSubseq(int arr[], int N)
{
    set<int>s;
    for(int i=0;i<N;i++)
    {
        s.insert(arr[i]);
    }
    int res = 0;
    while(!s.empty())
    {   
        auto it = s.begin();   
        int x = *it++;
        s.erase(x);
        int lb,ub;
        lb = x - 1;
        while(s.find(lb) != s.end())
        {
            s.erase(lb);
            lb--;
        }
        ub = x + 1;
        while(s.find(ub) != s.end())
        {
            s.erase(ub);
            ub++;
        }
        res = max(res,ub-lb-1);
    }
    return res;
}