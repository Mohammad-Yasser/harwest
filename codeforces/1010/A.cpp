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

bool valid(const vector<Double>& v, Double m, Double x) {
  for (auto a : v) {
    if (x * (a - 1) < m) return false;
    x -= (m + x) / a;
  }
  return true;
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
  vector<int> a(n), b(n);
  cin >> a >> b;
  rotate(begin(b), begin(b) + 1, end(b));
  vector<Double> v;
  v.reserve(2 * n);
  for (int i = 0; i < n; ++i) {
    v.emplace_back(a[i]);
    v.emplace_back(b[i]);
    if (min(a[i], b[i]) == 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  Double low = 0, high = 1e9 + 5;
  for (int i = 0; i < 100; ++i) {
    Double mid = (low + high) / 2;
    if (valid(v, m, mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << fixed << setprecision(10) << low << endl;
  return 0;
}
