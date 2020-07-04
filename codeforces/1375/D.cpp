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

int getMex(vector<int> v) {
  sort(v.rbegin(), v.rend());
  int res = 0;
  while (!v.empty() && v.back() <= res) {
    res += (v.back() == res);
    v.pop_back();
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
  vector<int> v, res;
  while (t--) {
    int n;
    cin >> n;
    v.resize(n);
    cin >> v;
    res.clear();
    while (!is_sorted(all(v))) {
      int mex = getMex(v);
      if (mex == n) {
        res.emplace_back(-1);
        for (int i = 0; i < n; ++i) {
          if (v[i] != i) {
            if (res.back() == -1 || v[i] < v[res.back()]) {
              res.back() = i;
            }
          }
        }
        v[res.back()] = mex;
      } else {
        v[mex] = mex;
        res.emplace_back(mex);
      }
      ++res.back();
    }
    cout << sz(res) << endl;
    cout << res << endl;
  }

  return 0;
}