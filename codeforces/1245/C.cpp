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

string hands = "RPS";
const int N = 1e5 + 5;
const int MOD = round(1e9 + 7);
int dp[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;

  if (s.find('m') != string::npos || s.find('w') != string::npos) {
    cout << 0 << endl;
    return 0;
  }

  s = " " + s;
  dp[0] = dp[1] = 1;
  for (int i = 2; i < s.size(); ++i) {
    string tmp = s.substr(i - 1, 2);
    if (tmp == "uu" || tmp == "nn") {
      dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    } else {
      dp[i] = dp[i - 1];
    }
  }

  cout << dp[s.size() - 1] << endl;

}
