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
typedef long double Double;

const int N = 2e5 + 5;

int pre[N];
int suf[N];
string s, t;

void build() {
  int curr_t = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == t[curr_t]) {
      ++curr_t;
    }
    pre[i + 1] = curr_t;
  }

  curr_t = t.size() - 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (curr_t >= 0 && s[i] == t[curr_t]) {
      --curr_t;
    }
    suf[i] = t.size() - curr_t - 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> s >> t;
  build();

  int res = 0;
  int r = 0;
  for (int i = 0; i < s.size(); ++i) {
    while (r < s.size() && pre[i] + suf[r + 1] == t.size()) {
      ++r;
    }
    // cout << i << " " << pre[i] << " " << suf[i] << " " << r << endl;
    res = max(res, r - i);
  }

  cout << res << endl;

  return 0;
}