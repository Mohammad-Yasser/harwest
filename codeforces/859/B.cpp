#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;
const int N = 1003;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  int res = INT_MAX;

  for (int i = 1; i <= n; ++i) {
    int j = n / i;
    int rem = n % i;

    res = min(res, (i + j) * 2 + 2 * (rem != 0));
  }

  cout << res;
}

