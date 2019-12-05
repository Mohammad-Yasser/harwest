#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e5 + 5;
const int LOG = log2(N) + 5;
constexpr int MOD = 998244353;

int p[N];

int power(int b, int p) {
  if (p == 0) return 1;
  int res = power(b, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * b % MOD;
  }
  return res;
}

const int INV100 = power(100, MOD - 2);

struct Elem {
  int a, b;
  int p_prod;
  int cnt;
};
int n;

struct SparseTable {
  Elem table[N][LOG];
  int lg2[N];

  SparseTable() {
    memset(table, 0, sizeof(table));
    memset(lg2, 0, sizeof(lg2));
    n = 0;
  }

  Elem merge(const Elem& x, const Elem& y) {
    Elem res = x;
    res.a = (res.a - 1LL * x.p_prod * x.cnt % MOD + MOD) % MOD;
    res.b = (res.b + 1LL * x.p_prod * y.b) % MOD;
    res.a = (res.a + 1LL * x.cnt * x.p_prod) % MOD;
    res.a = (res.a + 1LL * y.a * x.p_prod) % MOD;
    res.p_prod = 1LL * x.p_prod * y.p_prod % MOD;
    res.cnt = (x.cnt + y.cnt) % MOD;
    return res;
  }

  void init() {
    for (int i = 2; i < n; i++)
      lg2[i] = lg2[i >> 1] + 1;
    for (int i = 0; i < n; i++) {
      table[i][0].cnt = 1;
      table[i][0].p_prod = 1LL * p[i] * INV100 % MOD;
      table[i][0].a = 1;
      table[i][0].b = 1LL * (100 - p[i]) * INV100 % MOD;
    }

    for (int j = 1; (1 << j) <= n; j++)
      for (int i = 0; i < n; i++) {
        if (i + (1 << (j - 1)) >= n) {
          table[i][j] = table[i][j - 1];
          continue;
        }
        table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      }
  }

  Elem query(int l, int r) {
    int k = lg2[r - l + 1];
    if ((1 << k) == r - l + 1) {
      return table[l][k];
    }
    return merge(table[l][k], query(l + (1 << k), r));
  }
} sp_table;

int calc(int l, int r) {
  auto elem = sp_table.query(l, r);
  return 1LL * elem.a * power((1 - elem.b + MOD) % MOD, MOD - 2) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  sp_table.init();
  set<int> checkpoints;
  checkpoints.insert(0);
  checkpoints.insert(n);

  int res = calc(0, n - 1);
  while (q--) {
    int u;
    cin >> u;
    --u;
    int diff = 0;
    bool erased = false;
    if (checkpoints.count(u) == 1) {
      checkpoints.erase(u);
      erased = true;
    }
    auto it = checkpoints.upper_bound(u);
    int r = *it;
    int l = *--it;
    diff = (MOD - calc(l, r - 1));
    diff = (diff + calc(l, u - 1)) % MOD;
    diff = (diff + calc(u, r - 1)) % MOD;

    if (erased) {
      res = (res - diff + MOD) % MOD;
    } else {
      res = (res + diff) % MOD;
      checkpoints.insert(u);
    }

    cout << res << endl;
  }

}
