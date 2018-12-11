#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  string s, t;
  cin >> n >> k >> s >> t;

  Long res = 0;
  int cnt_strings = 1;

  for (int i = 0; i < n; ++i) {
    if (cnt_strings < k) {
      cnt_strings = min(k, 2 * cnt_strings + t[i] - s[i] - 1);
    }
    res += cnt_strings;
  }

  cout << res;
}
