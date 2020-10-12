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

vector<Long> solve(const vector<Long>& v) {
  if (sz(v) <= 1) return {};
  Long g = v[0];
  for (Long x : v) g = __gcd(g, x);
  vector<Long> evens, odds;
  for (Long x : v) {
    x /= g;
    if (x % 2 == 0)
      evens.emplace_back(x);
    else
      odds.emplace_back(x);
  }
  auto tmp = solve(evens);
  for (auto x : tmp) odds.emplace_back(x);
  auto res = (sz(evens) < sz(odds) ? evens : odds);
  for (auto& x : res) x *= g;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<Long> v(n);
  cin >> v;
  auto res = solve(v);
  cout << sz(res) << endl;
  cout << res << endl;
  return 0;
}