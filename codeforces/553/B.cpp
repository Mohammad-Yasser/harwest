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

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 51;
const Long OO = 1e18 + 5;
Long memo[N];

Long getNoWays(int length) {
  if (length <= 1) return 1;
  Long& res = memo[length];
  if (res != -1) return res;
  return res = min(OO, getNoWays(length - 1) + getNoWays(length - 2));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif
  memset(memo, -1, sizeof memo);
  int n;
  Long k;
  cin >> n >> k;

  for (int curr = 1; curr <= n; ++curr) {
    if (getNoWays(n - curr) >= k) {
      cout << curr << " ";
      continue;
    }
    k -= getNoWays(n - curr);
    cout << curr + 1 << " " << curr << " ";
    ++curr;
  }
  cout << endl;

}
