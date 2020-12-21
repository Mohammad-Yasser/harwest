#ifndef Local
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
mt19937 rng(RANDOM);

struct chash {  // To use most bits rather than just the lowest ones:
  const uint64_t C = Long(4e18 * acos(0)) | 71;  // large odd number
  Long operator()(Long x) const { return __builtin_bswap64((x ^ RANDOM) * C); }
};

const int N = 5e5 + 5;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<Long> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    Long sum_c = 0;
    for (int i = 0; i < n; ++i) {
      c[i] = max(0LL, a[i] - b[(i - 1 + n) % n]);
      sum_c += c[i];
    }
    Long res = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
      res = min(res, sum_c - c[i] + a[i]);
    }
    cout << res << endl;
  }

  return 0;
}