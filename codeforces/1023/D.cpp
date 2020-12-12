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

const int N = 2e5 + 5;

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
vector<int> occ[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n, q;
  cin >> n >> q;

  vector<int> v(n);
  cin >> v;
  for (int i = 0; i < n; ++i) {
    if (v[i] == 0) {
      v[i] = N;
    } else {
      occ[v[i]].emplace_back(i);
    }
  }
  sparse_table.init(v, [](int x, int y) { return min(x, y); });
  for (int i = 1; i < N; ++i) {
    if (occ[i].empty()) continue;
    int mn = sparse_table.query(occ[i][0], occ[i].back());
    if (mn != i) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (occ[q].empty()) {
    auto it = find(all(v), N);
    if (it == end(v)) {
      cout << "NO" << endl;
      return 0;
    }
    *it = q;
  }
  cout << "YES" << endl;
  int prev = 1;
  for (int i = 0; i < n; ++i) {
    if (v[i] == N) v[i] = prev;
    prev = v[i];
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}