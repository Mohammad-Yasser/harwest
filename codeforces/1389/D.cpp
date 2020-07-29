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

int n, k;
int l1, r1;
int l2, r2;

Long solve() {
  if (r1 >= l2) {
    Long op0 = 1LL * n * (min(r1, r2) - max(l1, l2));
    if (op0 >= k) return 0;
    k -= op0;
    Long op1 = 1LL * n * (max(r1, r2) - l1) - op0;
    if (op1 >= k) {
      return k;
    }
    return op1 + 2 * (k - op1);
  }
  Long res = LLONG_MAX / 2;
  for (int i = 1; i <= n; ++i) {
    Long tmp = 1LL * i * (l2 - r1);
    Long op1 = 1LL * i * (r2 - l1);
    if (op1 >= k) {
      res = min(res, tmp + k);
    } else {
      res = min(res, tmp + op1 + 2 * (k - op1));
    }
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
    cin >> n >> k;
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    if (l1 > l2) {
      swap(l1, l2);
      swap(r1, r2);
    }
    cout << solve() << endl;
  }
  return 0;
}