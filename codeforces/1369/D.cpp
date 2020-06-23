#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 2e6 + 5;
const int MOD = round(1e9 + 7);
int memo[N][2];

int solve(int n, bool yellow) {
  if (n <= 2) return 0;
  if (n == 3) return 4 * !yellow;
  int& res = memo[n][yellow];
  if (res != -1) return res;
  if (yellow || n % 3 != 0) {
    res = (solve(n - 1, false) + 2LL * solve(n - 2, false)) % MOD;
    return res;
  }
  res = (4 + solve(n - 1, true) + 2LL * solve(n - 2, true)) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo, -1, sizeof memo);

  for (int i = 1; i < N; ++i) solve(i, true), solve(i, false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n, false) << endl;
  }
  return 0;
}