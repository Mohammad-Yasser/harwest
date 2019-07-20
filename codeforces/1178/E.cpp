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

const int MOD = 998244353;

string rem(const string& s, char c) {
  string res;
  for (char x : s) {
    if (x != c) {
      res += x;
    }
  }
  return res;
}

string solve(const string& s) {
  string res;
  for (char c : s) {
    if (res.empty() || c != res.back()) {
      res += c;
    }
  }

  if (res.back() != res[0]) {
    res.pop_back();
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  string s;
  cin >> s;

  int r = s.size() - 1;
  int l = 0;

  string res;

  while (l < r) {
    if (s[l] == s[r]) {
      res.push_back(s[l]);
      --r;
      ++l;
      continue;
    }
    if (l < r - 1 && s[l] == s[r - 1]) {
      res.push_back(s[l]);
      --r;
      --r;
      ++l;
      continue;
    }
    if (l + 1 < r && s[l + 1] == s[r]) {
      res.push_back(s[l + 1]);
      --r;
      ++l;
      ++l;
      continue;
    }
    if (l + 1 < r - 1 && s[l + 1] == s[r - 1]) {
      res.push_back(s[l + 1]);
      --r;
      --r;
      ++l;
      ++l;
      continue;
    }
    break;
  }

  string rev = res;
  reverse(rev.begin(), rev.end());

  if (l <= r) {
    res += s[l];
  }

  res += rev;

  if (res.size() < s.size()  / 2) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  cout << res << endl;

}
