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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long Long;
typedef vector<int> vi;

const int RANDOM =
    chrono::high_resolution_clock::now().time_since_epoch().count();
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

  int n;
  cin >> n;

  vector<int> v;
  for (int i = 2; i <= n; ++i) {
    int smallest_divisor = i;
    for (int j = 2; j * j <= n; ++j) {
      if (i % j == 0) {
        smallest_divisor = j;
        break;
      }
    }
    v.emplace_back(i / smallest_divisor);
  }

  sort(all(v));
  int res = 1;
  for (int x : v) {
    cout << x << " ";
  }

  return 0;
}