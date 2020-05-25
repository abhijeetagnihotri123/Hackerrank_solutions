#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int L = s.length();
  int rows, cols;
  float sqrt = pow(L, 0.5);
  if (ceil(sqrt) == floor(sqrt)) {
    rows = cols = ceil(sqrt);
  } else {
    rows = floor(sqrt);
    cols = ceil(sqrt);
  }
  if (rows * cols < L) {
    rows++;
  }
  vector<string> a;
  vector<string> b;
  string str = "";
  int c = 0;
  int j = 0;
  int index = 0;
  int i = 0;
  for (int i = 0; i < L; i++) {
    if ((i + 1) % cols == 0) {
      str = str + s[i];
      a.push_back(str);
      str = "";
    } else {
      str = str + s[i];
    }
  }
  if (str.length() != 0) {
    a.push_back(str);
  }
  str = "";
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < cols; j++) {
      if (a[i].length() == cols) {
        ;
      } else {
        for (int c = 1; c <= (cols - a[i].length()); c++) {
          a[i] = a[i] + "*";
        }
      }
    }
  }
  str = "";

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      str = str + a[j][i];
    }
    b.push_back(str);
    str = "";
  }
  for (int i = 0; i < b.size(); i++) {
    for (int j = 0; j < b[i].length(); j++) {
      if (b[i][j] == '*') {
        ;
      } else {
        cout << b[i][j];
      }
    }
    cout << " ";
  }
  return 0;
}

