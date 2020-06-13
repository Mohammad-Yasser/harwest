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

int arr[N];
int sum[N];

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
    int n, x;
    cin >> n >> x;
    memset(sum, 0, sizeof sum);
    int l = -1, r = n;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
      arr[i] %= x;
      sum[i] = (arr[i] + sum[i - 1]) % x;
      if (l == -1 && arr[i] != 0) {
        l = i;
      }
      if (arr[i] != 0) {
        r = i;
      }
    }
    int res = 0;
    if (l == -1) {
      res = -1;
    } else if (sum[r] != sum[l - 1]) {
      res = n;
    } else {
      res = max(r - 1, n - l);
    }
    cout << res << endl;
  }

  return 0;
}