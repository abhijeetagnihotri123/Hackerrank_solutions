#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int count, max = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    count = 0;
    for (int j = i - 1; j >= 0; j--) {
      if ((a[i] - a[j]) < 2) {
        count++;
      }
    }
    if (count > max) {
      max = count;
    }
  }
  cout << max + 1;
  return 0;
}

