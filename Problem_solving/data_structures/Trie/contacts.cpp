#include <iostream>
#include <iterator>
#include <map>
#include <string>
using namespace std;
int main() {
  map<string, int> m;
  int n;
  cin >> n;
  while (n--) {
    string query, str;
    cin >> query >> str;
    if (query == "add") {
      string aux;
      for (int i = 1; i <= str.length(); i++) {
        aux = str.substr(0, i);
        m[aux]++;
      }
    } else {
      auto it = m.find(str);
      if (it != m.end()) {
        cout << it->second << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
}
