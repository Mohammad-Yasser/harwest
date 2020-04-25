#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef vector<int> vi;

const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {  // To use most bits rather than just the lowest ones:
  const uint64_t C = Long(4e18 * acos(0)) | 71;  // large odd number
  Long operator()(Long x) const { return __builtin_bswap64((x ^ RANDOM) * C); }
  int operator()(int x) const { return (*this)(Long(x)); }
};

__gnu_pbds::gp_hash_table<int, Long, chash> hash_map({}, {}, {}, {}, {1 << 16});

const int N = 1e5 + 5;
const int LOG = 19;

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

int n;

int bs(int ind, int g) {
  int l = ind, r = n, ans = n;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (sparse_table.query(ind, mid) < g) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  vector<int> v(n);
  for (int& x : v) {
    cin >> x;
  }
  v.emplace_back(1);
  sparse_table.init(v, [](int x, int y) { return __gcd(x, y); });

  for (int i = 0; i < n; ++i) {
    int prev = i;
    int g = v[i];
    while (prev != n) {
      int curr = bs(i, g);
      hash_map[g] += curr - prev;
      prev = curr;
      g = __gcd(g, v[prev]);
    }
  }

  int q;

  cin >> q;

  while (q--) {
    int x;
    cin >> x;
    cout << hash_map[x] << endl;
  }

  return 0;
}
