#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

// Source:
// https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/KMP.h
vector<int> kmp(const string& s) {
  vector<int> p(sz(s));
  for (int i = 1; i < sz(s); ++i) {
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string a, b;
  cin >> a >> b;
  auto pi = kmp(b);
  int cnt_ones = count(all(a), '1');
  string res = b;
  while (sz(res) < sz(a)) {
    res += b.substr(pi.back());
  }
  while (sz(res) > sz(a)) {
    res.pop_back();
  }
  cnt_ones -= count(all(res), '1');
  for (int i = sz(res) - 1; i >= 0 && cnt_ones != 0; --i) {
    if (res[i] == '0' && cnt_ones > 0) {
      res[i] = '1';
      --cnt_ones;
    }
    if (res[i] == '1' && cnt_ones < 0) {
      res[i] = '0';
      ++cnt_ones;
    }
  }
  cout << res << endl;
  return 0;
}