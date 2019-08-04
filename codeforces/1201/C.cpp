#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 2e5 + 5;

Long a[N];

int n;
Long k;

Long getCost(Long median) {
  Long res = 0;
  for (int i = n / 2; i < n; ++i) {
    res += max(0LL, median - a[i]);
  }
  return res;
}

Long solve() {
  Long low = a[n / 2], high = INT_MAX, ans = a[n / 2];

  while (low <= high) {
    Long mid = (low + high) / 2;
    if (getCost(mid) <= k) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a , a + n);

  cout << solve() << endl;

}
