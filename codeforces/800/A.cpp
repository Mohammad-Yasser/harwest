#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef unsigned long long Long;

const int N = 1e5 + 5;

int a[N];
int b[N];

int n;
int p;

bool can(double t) {
  double needed = 0;
  for (int i = 0; i < n; ++i) {
    needed += max(0.0, a[i] * t - b[i]);
  }
  return needed <= t * p;
}

double solve() {
  double low = 0, high = 1e10 + 5;
  for (int i = 0; i < 150; ++i) {
    double mid = (low + high) / 2;
    if (can(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return low;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> p;

  Long sum_a = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    sum_a += a[i];
  }

  if (sum_a <= p) {
    cout << -1;
    return 0;
  }

  cout << fixed << setprecision(10) << solve() << endl;

}

