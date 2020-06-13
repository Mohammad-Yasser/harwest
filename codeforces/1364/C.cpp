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
#define rall(v) rbegin(v), rend(v)
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

typedef long long Long;
typedef double Double;
typedef vector<int> vi;

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

const int N = 1e5 + 5;

int a[N];
int b[N];
bool vis[N];

int n;
bool valid() {
  memset(vis, 0, sizeof vis);
  int mex = 0;
  for (int i = 1; i <= n; ++i) {
    vis[b[i]] = true;
    while (vis[mex]) ++mex;
    if (a[i] != mex) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  memset(b, -1, sizeof b);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] != a[i - 1]) {
      b[i] = a[i - 1];
      vis[b[i]] = true;
    }
  }
  int curr = max(0, a[n] - 1);
  while (curr != 0 && vis[curr]) --curr;
  for (int i = n; i >= 1; --i) {
    if (b[i] == -1) {
      if (a[i] >= curr) {
        b[i] = (curr == 0 ? N : curr - 1);
      } else {
        b[i] = curr;
        do {
          --curr;
        } while (curr != 0 && vis[curr]);
      }
    }
  }

  if (valid()) {
    for (int i = 1; i <= n; ++i) {
      cout << b[i] << " ";
    }
    cout << endl;
    return 0;
  }
  cout << -1 << endl;

  return 0;
}