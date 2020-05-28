#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

const int N = 100005;

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

  // Not quite tested.
  // T query(int l, int r) const {
  //   int lg = 32 - __builtin_clz(r - l + 1) - 1;
  //   if ((1 << lg) == r - l + 1) {
  //     return sp[lg][l];
  //   }
  //   return func(sp[lg][l], query(l + (1 << lg), r));
  // }
};

SparseTable<Long> min_sparse_table, max_sparse_table;
int first_left[N];
int first_right[N];
int arr[N];
int n;

void buildLeft() {
  first_left[1] = 0;
  for (int i = 2; i <= n; ++i) {
    int& res = first_left[i];
    res = i - 1;
    while (res > 0 && arr[i] > arr[res]) {
      res = first_left[res];
    }
  }
}

void buildRight() {
  first_right[n] = n + 1;
  for (int i = n - 1; i >= 1; --i) {
    int& res = first_right[i];
    res = i + 1;
    while (res <= n && arr[i] >= arr[res]) {
      res = first_right[res];
    }
  }
}

Long prefix_sum[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  vector<Long> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    prefix_sum[i] = arr[i] + prefix_sum[i - 1];
  }

  buildLeft();
  buildRight();

  min_sparse_table.init(prefix_sum, [](int x, int y) { return min(x, y); });
  max_sparse_table.init(prefix_sum, [](int x, int y) { return max(x, y); });

  Long res = LLONG_MIN;
  for (int i = 1; i <= n; ++i) {
    Long l = first_left[i];
    Long r = first_right[i] - 1;
    r = max_sparse_table.query(i, r);
    l = min_sparse_table.query(l, i - 1);
    res = max(res, r - l - arr[i]);
  }
  cout << res << endl;
  return 0;
}