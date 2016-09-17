#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  int t = 1e9;
  int ans = 0;
  while (n--) {
    int tmp;
    cin >> tmp;
    if (tmp - t > c) {
      ans = 0;
    }
    ++ans;
    t = tmp;
  }
  cout << ans ;
  return 0;
}
