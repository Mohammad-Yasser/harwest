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

int n;
int k;

int arr[N];

int main(int argc, char *argv[]) {
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
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }

    int res = INT_MAX;
    int best = 1;

    for (int i = 1; i + k <= n; ++i) {
      int tmp = (arr[i + k] - arr[i] + 1) / 2;
      if (tmp < res) {
        res = tmp;
        best = (arr[i + k] + arr[i]) / 2;
      }
    }

    cout << best << endl;
  }

}
