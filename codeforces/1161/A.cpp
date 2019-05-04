#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

const int N = 2e5 + 5;

int arr[N];
int first[N];
int last[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  fill(first , first + N , N);
  for (int i = 1; i <= k; ++i) {
    cin >> arr[i];
    if (first[arr[i]] == N) {
      first[arr[i]] = i;
    }
    last[arr[i]] = i;
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i - 1; j <= i + 1; ++j) {
      if (j < 1 || j > n) continue;
      res += (last[j] < first[i]);
    }
  }
  cout << res << endl;

}
