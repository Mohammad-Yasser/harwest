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

const int A = 27;
vector<int> occ[A];

string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> s;

  for (int i = 0; i < n; ++i) {
    occ[s[i] - 'a'].push_back(i);
  }

  int m;
  cin >> m;

  while (m--) {
    string tmp;
    cin >> tmp;
    vector<int> cnt(A, 0);
    for (char c : tmp) {
      ++cnt[c - 'a'];
    }

    int res = 0;
    for (int i = 0; i < A; ++i) {
      if (cnt[i] != 0) {
        res = max(res, occ[i][cnt[i] - 1] + 1);
      }
    }

    cout << res << endl;
  }
}
