#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

const int N = 2e5 + 1;

int nCk[N], k, n;

inline int Power(int b, int p) {
  int res = 1, curr = b;
  for (int i = 0; p >= (1 << i); ++i) {
    if (p & (1 << i)) res = 1LL * res * curr % MOD;
    curr = 1LL * curr * curr % MOD;
  }
  return res;
}

inline void BuildnCk() {
  nCk[k] = 1;
  for (int n = k + 1; n < N; ++n)
    nCk[n] = (1LL * nCk[n - 1] * n % MOD) *
             (1LL * Power(n - k, MOD - 2)) % MOD;
}

int main() {
  cin >> n >> k;
  BuildnCk();

  map<int, int> cnt;
  while (n--) {
    int l, r;
    cin >> l >> r;
    ++cnt[l];
    --cnt[r + 1];
  }


  auto it = cnt.begin();
  auto nxt = it;

  int res = 0;
  int curr = 0;
  for (++nxt; nxt != cnt.end(); ++it, ++nxt) {
    curr += it->second;
    res = (res + 1LL * (nxt->first - it->first) * nCk[curr]) % MOD;
  }

  cout << res << endl;

  return 0;
}
