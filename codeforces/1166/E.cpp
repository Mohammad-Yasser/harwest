#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
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
typedef double Double;

const int N = 1e4 + 5;

int cnt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int m, n;
  cin >> m >> n;

  vector<bitset<N>> v(m);
  for (auto& bt : v) {
    int s;
    cin >> s;
    while (s--) {
      int x;
      cin >> x;
      bt[x] = true;
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      if ((v[i] & v[j]).count() == 0) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }

  cout << "possible" << endl;

  return 0;
}