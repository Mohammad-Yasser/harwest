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
    int n, x;
    cin >> n >> x;
    Long sum = 0;
    vector<int> a(n);
    for (int& x : a) {
      cin >> x;
      sum += x;
    }
    sort(a.rbegin(), a.rend());
    while (!a.empty() && sum / a.size() < x) {
      sum -= a.back();
      a.pop_back();
    }
    cout << a.size() << endl;
  }

  return 0;
}