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
typedef __float128 Double;

const int N = 1003;

template <typename T>
T abs(const T& x) {
  if (x >= 0) return x;
  return -x;
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
  vector<Long> candidates;
  while (t--) {
    Long h, c, tmp;
    cin >> h >> c >> tmp;
    Long low = 0, high = round(1e7 + 1), ans = 0;
    while (low <= high) {
      Long mid = (low + high) / 2;
      Double avg = 1.0 * (mid * c + (mid + 1) * h) / (2 * mid + 1);
      if (avg < tmp) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    candidates.clear();
    candidates.emplace_back(2);
    for (int i = -1; i <= 1; ++i) {
      if (2 * (ans + i) + 1 > 0) candidates.emplace_back(2 * (ans + i) + 1);
    }
    sort(all(candidates));
    Double best = 1e35;
    Long res = 1;
    for (Long n : candidates) {
      Double avg = Double(1.0) * (n / 2 * c + (n + 1) / 2 * h) / n;
      Double diff = abs(avg - tmp);
      if (diff < best) {
        best = diff;
        res = n;
      }
    }
    cout << res << endl;
  }

  return 0;
}