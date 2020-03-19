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
#define sz(x) ((int)(x.size()))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long Long;
typedef vector<int> vi;

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

array<vi, 2> manacher(const string& s) {
  int n = sz(s);
  array<vi, 2> p = { vi(n + 1), vi(n) };
  rep(z, 0, 2)
    for (int i = 0, l = 0, r = 0; i < n; i++) {
      int t = r - i + !z;
      if (i < r) p[z][i] = min(t, p[z][l + t]);
      int L = i - p[z][i], R = i + p[z][i] - !z;
      while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
        p[z][i]++, L--, R++;
      if (R > r) l = L, r = R;
    }
  return p;
}

string solve(const string& s) {
  int l = 0, r = s.size() - 1;
  while (l < r && s[l] == s[r]) {
    ++l, --r;
  }
  if (l >= r) return s;
  string middle = s.substr(l, r - l + 1);
  auto lps = manacher(middle);
  int max_pre = 0, max_suff = 0;
  for (int i = 0; i < middle.size(); ++i) {
    int beg_0 = i - lps[0][i];
    int beg_1 = i - lps[1][i];
    int end_0 = i + lps[0][i] - 1;
    int end_1 = i + lps[1][i];
    if (beg_0 == 0) {
      max_pre = max(max_pre, end_0 - beg_0 + 1);
    }
    if (beg_1 == 0) {
      max_pre = max(max_pre, end_1 - beg_1 + 1);
    }
    if (end_0 + 1 == sz(middle)) {
      max_suff = max(max_suff, end_0 - beg_0 + 1);
    }
    if (end_1 + 1 == sz(middle)) {
      max_suff = max(max_suff, end_1 - beg_1 + 1);
    }
  }
  string res = s.substr(0, l);
  if (max_pre > max_suff) {
    res += middle.substr(0, max_pre);
  } else {
    res += middle.substr(sz(middle) - max_suff);
  }

  res += s.substr(r + 1);
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }

}
