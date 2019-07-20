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

const int N = 1e6 + 5;

int w_cnt[N];

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
    if (i != 0) {
      w_cnt[i] = w_cnt[i - 1];
    }
    if (i + 1 < s.size() && s.substr(i, 2) == "vv") {
      ++w_cnt[i];
    }
  }

  Long res = 0;

  for (int i = 1; i + 1 < s.size(); ++i) {
    if (s[i] == 'o') {
      res += 1LL * w_cnt[i] * (w_cnt[s.size() - 1] - w_cnt[i]);
    }
  }

  cout << res << endl;

}
