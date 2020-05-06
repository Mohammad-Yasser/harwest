#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
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

template <typename T>
void minimize(T& x, const T& y) {
  x = min(x, y);
}

template <typename T>
void maximize(T& x, const T& y) {
  x = max(x, y);
}

typedef long long Long;

const int N = 2e5 + 5;

int vis[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;
  set<int> st;

  for (int cs = 1; cs <= t; ++cs) {
    int n;
    cin >> n;
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      x = ((x + i) % n + n) % n;
      if (vis[x] == cs) {
        valid = false;
      }
      vis[x] = cs;
    }
    cout << (valid ? "YES" : "NO") << endl;
  }

  return 0;
}
