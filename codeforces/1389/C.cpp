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

const int A = 10;

vector<int> occ[A];
string s;

void buildOcc() {
  for (int i = 0; i < A; ++i) {
    occ[i].clear();
  }
  for (int i = 0; i < sz(s); ++i) {
    occ[s[i] - '0'].emplace_back(i);
  }
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
    cin >> s;
    buildOcc();
    int res = 0;
    for (auto& o : occ) {
      res = max(res, sz(o));
    }

    for (int i = 0; i < A; ++i) {
      for (int j = 0; j < A; ++j) {
        if (i == j) continue;
        if (occ[i].empty() || occ[j].empty()) continue;
        array<int, 2> ind = {0, 0};
        array<int, 2> vals = {i, j};
        int cnt = 1;
        bool turn = 1;
        while (true) {
          while (ind[turn] < sz(occ[vals[turn]]) &&
                 occ[vals[turn]][ind[turn]] < occ[vals[!turn]][ind[!turn]]) {
            ++ind[turn];
          }
          if (ind[turn] == sz(occ[vals[turn]])) break;
          ++cnt;
          turn ^= 1;
        }
        res = max(res, cnt ^ (cnt & 1));
      }
    }

    cout << sz(s) - res << endl;
  }
  return 0;
}