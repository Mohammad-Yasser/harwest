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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& p : a) {
      cin >> p.first;
      p.second = p.first;
    }
    vector<int> res;
    while (sz(res) < n) {  // log max(a) iterations
      sort(all(a));
      res.emplace_back(a.back().second);
      int x = a.back().first;
      a.pop_back();
      while (!a.empty() && a.back().first == x) {
        res.emplace_back(a.back().second);
        a.pop_back();
      }
      for (auto& p : a) {
        p.first = __gcd(p.first, x);
      }
    }

    cout << res << endl;
  }

  return 0;
}