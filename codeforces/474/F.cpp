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

template <typename T, class F = function<T(const T&, const T&)>>
struct SparseTable {
  int n;
  vector<vector<T>> sp;
  F func;

  SparseTable() {}

  void init(const vector<T>& a, const F& f) {
    func = f;
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    sp.resize(max_log);
    sp[0] = a;
    for (int j = 1; j < max_log; ++j) {
      sp[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); ++i) {
        sp[j][i] = func(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T query(int l, int r) const {
    int lg = 32 - __builtin_clz(r - l + 1) - 1;
    return func(sp[lg][l], sp[lg][r - (1 << lg) + 1]);
  }
};

SparseTable<int> sparse_table_gcd, sparse_table_min;

map<int, vector<int>> occ;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  for (int i = 0; i < n; ++i) {
    occ[v[i]].emplace_back(i);
  }
  sparse_table_gcd.init(v, [](int x, int y) { return __gcd(x, y); });
  sparse_table_min.init(v, [](int x, int y) { return min(x, y); });
  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int g = sparse_table_gcd.query(l, r);
    int mn = sparse_table_min.query(l, r);
    if (g % mn == 0) {
      cout << r - l + 1 -
                  (upper_bound(all(occ[mn]), r) -
                   upper_bound(all(occ[mn]), l - 1))
           << endl;
    } else {
      cout << r - l + 1 << endl;
    }
  }

  return 0;
}