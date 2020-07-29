#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
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

vector<int> buildPrefixSum(const vector<int>& v) {
  vector<int> res(sz(v) + 1, 0);
  for (int i = 0; i < sz(v); ++i) {
    res[i + 1] = res[i] + v[i];
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
  int t;
  cin >> t;
  while (t--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n);
    cin >> v;
    vector<int> pre_sum = buildPrefixSum(v);
    int res = pre_sum[k + 1];
    for (int used_left = 0; used_left <= z; ++used_left) {
      int last = k - 2 * used_left;
      for (int i = 0; i + 1 <= last; ++i) {
        res = max(res, pre_sum[last + 1] + used_left * (v[i] + v[i + 1]));
        if (used_left < z && last >= 2) {
          res = max(res, pre_sum[last] + used_left * (v[i] + v[i + 1]) +
                             max(v[last], v[last - 2]));
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}