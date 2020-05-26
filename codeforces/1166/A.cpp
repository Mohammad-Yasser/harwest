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

int nC2(int n) { return n * (n - 1) / 2; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  map<char, int> mp;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ++mp[s[0]];
  }
  int res = 0;
  for (auto& p : mp) {
    int x = p.second / 2;
    int y = p.second - x;
    res += nC2(x) + nC2(y);
  }
  cout << res << endl;
  return 0;
}