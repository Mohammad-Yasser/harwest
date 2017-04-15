#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << n;
    return 0;
  }

  vector<int> v;

  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      v.push_back(i);
      n /= i;

      if (--k == 1) {
        if (n != 1) {
          v.push_back(n);
          goto r;
        } else {
          cout << -1;
          return 0;
        }
      }
    }
  }

  cout << -1;
  return 0;

  r:;
  for (int x : v) {
    cout << x << ' ';
  }
  return 0;
}
