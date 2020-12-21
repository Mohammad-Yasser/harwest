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

int getSum(const string& s) {
  int res = 0;
  for (char c : s) {
    if (c != '?') {
      res += c - '0';
    }
  }
  return res;
}

int getQ(const string& s) {
  int res = 0;
  for (char c : s) {
    if (c == '?') {
      ++res;
    }
  }
  return res;
}

// Proof: https://codeforces.com/blog/entry/69815?#comment-632499

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  string s;
  cin >> n >> s;
  string left = s.substr(0, s.size() / 2);
  string right = s.substr(s.size() / 2);
  int diff = getSum(left) - getSum(right);
  int cnt_left = getQ(left), cnt_right = getQ(right);

  if (9 * (cnt_right - cnt_left) == 2 * diff) {
    cout << "Bicarp" << endl;
    return 0;
  }

  cout << "Monocarp" << endl;

  return 0;
}