#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin>>q;
  while(q--)
  {  
  long long int n, s;
  s = 0;
  cin >> n;
  int c = 0;
  vector<int> bin;
  vector<int> bin_32(32, 0);
  while (n > 0) {
    int a = n % 2;
    bin.push_back(a);
    n = n / 2;
    c++;
  }
  
  while (c--) {
    bin_32[c] = bin[c];
  }
  for (int i = 31; i >= 0; i--) {
    if (bin_32[i] == 1) {
      ;
    } else if (bin_32[i] == 0) {
      s = s + pow(2, i);
    } else {
      ;
    }
  }
  cout << s <<endl;
  }
  return 0;
}

