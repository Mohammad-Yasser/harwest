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

template <class T>
vector<T> getPrimeFactorization(T n) {
  vector<T> res;
  for (int i = 2; 1LL * i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.emplace_back(i);
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n != 1) {
    res.emplace_back(n);
  }
  return res;
}

Long solve(Long p, Long q) {
  auto q_factors = getPrimeFactorization(q);
  Long res = 1;
  for (Long factor : q_factors) {
    Long curr = p;
    while (curr % q == 0) {
      curr /= factor;
    }
    res = max(res, curr);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;
  while (t--) {
    Long p, q;
    cin >> p >> q;
    cout << solve(p, q) << endl;
  }
  return 0;
}