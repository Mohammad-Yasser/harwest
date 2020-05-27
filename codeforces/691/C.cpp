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

void zero() {
  cout << 0 << endl;
  exit(0);
}

string trim(const string& s) {
  string res;
  int first_non_zero = 0;
  while (first_non_zero != s.size() && s[first_non_zero] == '0')
    ++first_non_zero;
  if (first_non_zero == s.size()) return "";
  res = s.substr(first_non_zero);
  if (res == ".") return "0";
  if (s.find('.') != string::npos) {
    while (res.back() == '0') res.pop_back();
    if (res.back() == '.') res.pop_back();
  }
  return res;
}

void solve(const string& s) {
  string res = trim(s);
  if (res == "0" || res.empty()) zero();
  int dot = res.find('.');
  if (dot == string::npos) {
    res += '.';
    dot = res.size() - 1;
  }
  int ex = 0;
  if (dot == 0) {
    do {
      swap(res[dot], res[dot + 1]);
      ++dot;
      --ex;
    } while (res[dot - 1] == '0');
    res = trim(res);
    dot = 1;
  }
  while (dot != 1) {
    swap(res[dot], res[dot - 1]);
    --dot;
    ++ex;
  }

  res = trim(res);

  if (ex == 0) {
    cout << res << endl;
    exit(0);
  }
  cout << res << "E" << ex << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;

  solve(s);

  return 0;
}