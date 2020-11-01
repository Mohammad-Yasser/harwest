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
#define rep(i, l, r) for (int i = l; i < r; ++i)
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
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 3e5 + 5;
const int MOD = 998244353;

int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}
int modInverse(int x) { return power(x, MOD - 2); }

int fact[N];
int inv_fact[N];
void buildFactorial() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
    inv_fact[i] = modInverse(fact[i]);
  }
}

int nCr(int n, int r) {
  int res = fact[n];
  res = 1LL * res * inv_fact[r] % MOD;
  res = 1LL * res * inv_fact[n - r] % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  buildFactorial();
  int n;
  cin >> n;
  vector<int> v(2 * n);
  cin >> v;
  sort(all(v));
  int res = 0;
  for (int i = 0, j = 2 * n - 1; i < j; ++i, --j) {
    res = (res + v[j] - v[i]) % MOD;
  }
  res = 1LL * res * nCr(2 * n, n) % MOD;
  cout << res << endl;

  return 0;
}