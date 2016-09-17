#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll k = 2;

  cout << 2 << '\n';
  while (k <= n) {
    cout << k * k * k + 2 * k * k + 1 << '\n';
    ++k;
  }

  return 0;
}
