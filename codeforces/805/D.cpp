#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int MOD = round(1e9 + 7);

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  string s;
  cin >> s;

  Long cnt_b = 0;

  Long res = 0;

  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == 'a') {
      res = (res + cnt_b) % MOD;
      cnt_b = 2 * cnt_b % MOD;
    } else {
      ++cnt_b;
    }
  }

  cout << res << '\n';
}

