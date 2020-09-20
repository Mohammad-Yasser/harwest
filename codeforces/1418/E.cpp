#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
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

const int MOD = 998244353;

template <typename T>
int power(T base, T p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}

int modInverse(int x) { return power(x, MOD - 2); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  cin >> d;
  sort(all(d));
  vector<int> prefix_sum(n + 1);
  for (int i = 0; i < n; ++i) {
    prefix_sum[i + 1] = (prefix_sum[i] + d[i]) % MOD;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    int lb = lower_bound(all(d), b) - begin(d);
    int cnt_larger = n - lb;
    if (cnt_larger < a) {
      cout << 0 << endl;
      continue;
    }
    int sum_larger = prefix_sum[n] - prefix_sum[lb];
    int res_larger = 1LL * sum_larger * (cnt_larger - a) % MOD;
    res_larger = 1LL * res_larger * modInverse(cnt_larger) % MOD;
    int p_smaller =
        1LL * (cnt_larger + 1 - a) * modInverse(cnt_larger + 1) % MOD;
    int res_smaller = 1LL * p_smaller * prefix_sum[lb] % MOD;
    int res = ((res_larger + res_smaller) % MOD + MOD) % MOD;
    cout << res << endl;
  }
  return 0;
}