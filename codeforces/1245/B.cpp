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

string hands = "RPS";

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
    int n;
    int arr[3] = { 0 };
    cin >> n >> arr[0] >> arr[1] >> arr[2];
    string bob, alice(n, 0);
    cin >> bob;
    int wins = 0;
    for (int i = 0; i < n; ++i) {
      int h = (hands.find(bob[i]) + 1) % 3;
      if (arr[h] > 0) {
        --arr[h];
        alice[i] = hands[h];
        ++wins;
      }
    }
    if (wins >= (n + 1) / 2) {
      cout << "YES" << endl;
      for (auto& c : alice) {
        if (c == 0) {
          for (int i = 0; i < 3; ++i) {
            if (arr[i] > 0) {
              --arr[i];
              c = hands[i];
              break;
            }
          }
        }
      }
      cout << alice << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
