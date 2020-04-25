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

__gnu_pbds::gp_hash_table<int, Long, chash> res({}, {}, {}, {}, {1 << 16});

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
  for (int& x : v) {
    cin >> x;
  }

  map<int, int> gcds;

  for (int i = 0; i < n; ++i) {
    map<int, int> nxt;
    ++nxt[v[i]];
    for (auto& g : gcds) {
      nxt[__gcd(g.first, v[i])] += g.second;
    }
    gcds = nxt;
    for (auto& g : gcds) {
      res[g.first] += g.second;
    }
  }

  int q;

  cin >> q;

  while (q--) {
    int x;
    cin >> x;
    cout << res[x] << endl;
  }

  return 0;
}
