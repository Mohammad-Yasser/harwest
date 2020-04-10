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

int getCnt(int curr, int n) {
  if (curr == 1) return 2 * (n - curr) - 1;
  if (curr == n) {
  }
  if (curr == 2) return 0;
  return 2 * (curr - 2) - 1;
}

int getNxt(int curr, int n) {
  if (curr == 1) return n;
  if (curr == 2) return 0;
  return curr - 1;
}

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
    Long l, r;
    cin >> n >> l >> r;
    --l;
    vector<int> seq;
    for (int i = 1; i <= n - 1; ++i) {
      if (seq.empty() && l >= 2 * (n - i)) {
        l -= 2 * (n - i);
        r -= 2 * (n - i);
        continue;
      }
      if (seq.size() > r) break;
      for (int j = i + 1; j <= n; ++j) {
        seq.emplace_back(i);
        seq.emplace_back(j);
      }
    }
    seq.emplace_back(1);
    for (int i = l; i < r; ++i) {
      cout << seq[i] << " ";
    }
    cout << endl;
  }

  return 0;
}