#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 1e4 + 5;

int arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m, k;
  cin >> n >> m >> k;

  if (n % 2 == 0) {
    cout << 0;
    return 0;
  }

  int min_odd = INT_MAX;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (~i & 1) {
      min_odd = min(min_odd, arr[i]);
    }
  }

  int l = 1 + n / 2;
  int cnt = m / l;

  cout << min(1LL * min_odd, 1LL * cnt * k);
}
