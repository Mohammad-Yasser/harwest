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
#define rep(i, l, r) for (int i = l; i < r; ++i)
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
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<string> grid(n);
    cin >> grid;
    vector<pair<int, int>> res(4);
    for (char i = '0'; i < '2'; ++i) {
      vector<pair<int, int>> tmp;
      if (grid[0][1] == i) {
        tmp.emplace_back(1, 2);
      }
      if (grid[1][0] == i) {
        tmp.emplace_back(2, 1);
      }
      if (grid[n - 1][n - 2] == (i ^ 1)) {
        tmp.emplace_back(n, n - 1);
      }
      if (grid[n - 2][n - 1] == (i ^ 1)) {
        tmp.emplace_back(n - 1, n);
      }
      if (sz(tmp) < sz(res)) res = tmp;
    }
    cout << sz(res) << endl;
    for (auto& p : res) {
      cout << p.first << " " << p.second << endl;
    }
  }
  return 0;
}