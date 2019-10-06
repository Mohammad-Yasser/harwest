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

const int N = 3e5 + 5;

int first[N];
int last[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int q;

  cin >> q;

  while (q--) {
    int n;
    cin >> n;
    fill(first, first + n + 1, -1);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      last[x] = i;
      if (first[x] == -1) {
        first[x] = i;
      }
    }
    int res = 1;
    int curr = 0;
    int nxt = N;
    int cnt = 0;

    for (int i = n; i >= 1; --i) {
      if (first[i] == -1) continue;
      ++cnt;
      if (last[i] > nxt) {
        curr = 1;
      } else {
        ++curr;
        res = max(res, curr);
      }
      nxt = first[i];
    }


    cout << cnt - res << endl;

  }

}
