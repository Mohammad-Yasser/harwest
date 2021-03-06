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

const int N = 2e5 + 5;
int arr[N];
int n;

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
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    bool found = false;
    for (int i = 0; i + 1 < n; ++i) {
      if (abs(arr[i] - arr[i + 1]) > 1) {
        cout << "YES" << endl;
        cout << i + 1 << " " << i + 2 << endl;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO" << endl;
    }

  }
}
