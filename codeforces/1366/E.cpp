#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

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

SparseTable<int> sparse_table;
map<int, vector<int>> occ;

const int MOD = 998244353;
int n, m;

int solve(const vector<int>& a, const vector<int>& b) {
  for (int i = 0; i < n; ++i) {
    occ[a[i]].emplace_back(i);
  }
  sparse_table.init(a, [](int x, int y) { return min(x, y); });
  int mn_a = *min_element(all(a));
  if (mn_a != b[0]) return 0;
  int curr = occ[mn_a].back() + 1;
  int res = 1;

  for (int i = 1; i < m; ++i) {
    while (mn_a < b[i]) {
      curr = occ[mn_a].back() + 1;
      if (curr == n) return 0;
      mn_a = sparse_table.query(curr, n - 1);
    }
    // cout << i << " " << mn_a << endl;
    if (mn_a > b[i]) return 0;
    int nxt = occ[mn_a].back() + 1;
    res = 1LL * res * (nxt - curr) % MOD;
    curr = nxt;
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

  cin >> n >> m;

  vector<int> a(n);
  cin >> a;
  vector<int> b(m);
  cin >> b;
  cout << solve(a, b) << endl;
  return 0;
}