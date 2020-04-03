#include <bits/stdc++.h>

#include <ext/numeric>

#define all(v) begin(v), end(v)

using namespace std;
using namespace __gnu_cxx;
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int d, m;
    cin >> d >> m;
    if (m == 1) {
      cout << 0 << endl;
      continue;
    }
    int res = 0;
    vector<int> v;
    for (int msb = 0; (1LL << msb) <= d; ++msb) {
      int lower_bound = (1 << msb);
      int upper_bound = min(d + 1LL, 2LL << msb);
      v.emplace_back(upper_bound - lower_bound);
    }
    for (int x : v) {
      res = (res + 1LL * res * x) % m;
      res = (res + x) % m;
    }
    cout << res << endl;
  }

  return 0;
}
