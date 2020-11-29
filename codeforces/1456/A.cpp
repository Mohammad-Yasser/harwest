#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
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

const int N = 1e5 + 5;

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
    int n, p, k;
    cin >> n >> p >> k;
    string state;
    cin >> state;
    int x, y;
    cin >> x >> y;
    vector<int> suffix_sum(n);
    for (int i = n - 1; i >= 0; --i) {
      suffix_sum[i] = (state[i] == '0') * x;
      if (i + k < n) {
        suffix_sum[i] += suffix_sum[i + k];
      }
    }
    int res = suffix_sum[p - 1];
    for (int i = 0; i < n - p; ++i) {
      res = min(res, (i + 1) * y + suffix_sum[i + p]);
    }
    cout << res << endl;
  }

  return 0;
}