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

struct SparseTable {
  int table[N][LOG];
  int lg2[N], n;

  SparseTable() {
    memset(table, 0, sizeof(table));
    memset(lg2, 0, sizeof(lg2));
    n = 0;
  }

  void init(vector<int>& a) {
    n = a.size();
    for (int i = 2; i < n; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int i = 0; i < n; i++) table[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
      for (int i = 0; i < n; i++) {
        if (i + (1 << (j - 1)) >= n) {
          table[i][j] = table[i][j - 1];
          continue;
        }
        table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      }
  }

  int query(int l, int r) {
    int k = lg2[r - l + 1];
    return __gcd(table[l][k], table[r - (1 << k) + 1][k]);
  }
} sparse_table;
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
  sparse_table.init(v);

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
