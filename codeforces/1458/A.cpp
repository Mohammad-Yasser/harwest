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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;
  vector<Long> a(n);
  cin >> a;

  Long g = -1;
  for (int i = 1; i < n; ++i) {
    Long d = abs(a[i] - a[0]);
    if (g == -1) g = d;
    g = __gcd(g, d);
  }

  while (m--) {
    Long b;
    cin >> b;
    if (g == -1) {
      cout << a[0] + b << " ";
    } else {
      cout << __gcd(g, a[0] + b) << " ";
    }
  }

  cout << endl;

  return 0;
}