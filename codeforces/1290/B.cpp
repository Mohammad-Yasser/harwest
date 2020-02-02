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

const int A = 30;
const int N = 2e5 + 5;

int cnt[A][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      cnt[c - 'a'][i + 1] = cnt[c - 'a'][i] + (s[i] == c);
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int l , r;
    cin >> l >> r;
    --r , --l;
    if (l == r) {
      cout << "YES" << endl;
      continue;
    }
    if (s[l] != s[r]) {
      cout << "YES" << endl;
      continue;
    }
    int distinct = 0;
    for (int i = 0 ; i < A ; ++i) {
      distinct += (cnt[i][r + 1] != cnt[i][l]);
    }
    if (distinct >= 3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

}
