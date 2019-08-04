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

const int N = 1e5 + 5;

int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  Long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum % 2 != 0) {
    cout << "NO";
    return 0;
  }

  sort(a, a + n);

  if (a[n - 1] > sum - a[n - 1]) {
    cout << "NO";
    return 0;
  }

  cout << "YES" << endl;
}
