#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 1e5 + 5;

Long arr[N];
Long max_p[N];
Long max_r[N];

Long p, q, r;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> p >> q >> r;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    max_p[i] = p * arr[i];
    if (i == 1) {
      continue;
    }
    max_p[i] = max(max_p[i], max_p[i - 1]);
  }

  for (int i = n; i >= 1; --i) {
    max_r[i] = r * arr[i];
    if (i == n) {
      continue;
    }
    max_r[i] = max(max_r[i], max_r[i + 1]);
  }

  Long res = LLONG_MIN;

  for (int i = 1; i <= n; ++i) {
    res = max(res, max_p[i] + max_r[i] + q * arr[i]);
  }

  cout << res;

}
