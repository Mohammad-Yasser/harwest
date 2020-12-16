#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
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

Long solve(const vector<int>& v, int length, int t) {
  if (sz(v) <= 1) return 0;
  t *= 2;
  Long res = (t / length + 1) * 1LL * (sz(v) - 1) * sz(v);
  vector<int> conc_v = v;
  for (int i = 0; i < sz(v); ++i) {
    conc_v.emplace_back(v[i] + length);
  }
  t %= length;
  int l = sz(conc_v) - 1;
  for (int i = sz(conc_v) - 1; i >= sz(v); --i) {
    while (conc_v[i] - conc_v[l] <= t) {
      --l;
    }
    res -= sz(v) - i + l;
  }
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

  int n, l, t;
  cin >> n >> l >> t;
  vector<int> a(n);
  cin >> a;

  cout << fixed << setprecision(10) << solve(a, l, t) / 4.0 << endl;

  return 0;
}