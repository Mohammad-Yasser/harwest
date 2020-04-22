#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  map<int, int> cnt;

  bool win = false;

  for (int i = 0; i < n; ++i) {
    win ^= (i & 1);
    int x;
    cin >> x;
    win ^= (x & 1);
    ++cnt[x];
  }

  int cnt_twos = 0;
  for (auto& p : cnt) {
    if (p.second < 2) continue;
    if (p.second > 2 || cnt[p.first - 1] > 0 || p.first == 0 || cnt_twos > 0) {
      cout << "cslnb" << endl;
      return 0;
    }
    ++cnt_twos;
  }

  cout << (win ? "sjfnb" : "cslnb") << endl;

  return 0;
}
