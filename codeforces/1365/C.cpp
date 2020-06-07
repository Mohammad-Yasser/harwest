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

const int N = 2e5 + 5;

int pos[N];
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  vector<int> a, b;
  int n;
  cin >> n;
  a.resize(n);
  b.resize(n);
  cin >> a >> b;
  for (int i = 0; i < n; ++i) {
    pos[b[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    b[pos[a[i]]] = i;
  }

  for (int i = 0; i < n; ++i) {
    ++cnt[(i - b[i] + n) % n];
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = max(res, cnt[i]);
  }

  cout << res << endl;

  return 0;
}