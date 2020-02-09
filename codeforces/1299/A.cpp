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

// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;

int arr[N];
int pre[N];
int suf[N];

int f(int x, int y) {
  return (x | y) - y;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    pre[i] = pre[i - 1] | arr[i];
  }

  for (int i = n; i >= 1; --i) {
    suf[i] = suf[i + 1] | arr[i];
  }

  int res = 0;
  int best_start = 1;
  for (int i = 1; i <= n; ++i) {
    int tmp = f(arr[i], pre[i - 1] | suf[i + 1]);
    if (tmp >= res) {
      res = tmp;
      best_start = i;
    }
  }
  cout << arr[best_start] << " ";
  for (int i = 1; i <= n; ++i) {
    if (i != best_start) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;

  return 0;
}
