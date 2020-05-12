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
typedef double Double;

const int N = 2e5 + 5;
int arr[N];
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
    int n, k;
    cin >> n >> k;
    bool k_appeared = false;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x == k) {
        x = 1;
        k_appeared = true;
      } else if (x < k) {
        x = 0;
      } else if (x > k) {
        x = 2;
      }
      arr[i] = x;
    }
    if (!k_appeared) {
      cout << "no" << endl;
      continue;
    }
    if (n == 1) {
      cout << "yes" << endl;
      continue;
    }
    bool valid = false;
    for (int i = 0; i + 1 < n; ++i) {
      int tmp = (!arr[i] + !arr[i + 1]);
      if (tmp == 0) {
        valid = true;
        break;
      }
      if (i + 2 < n) {
        tmp += !arr[i + 2];
        if (tmp == 1) {
          valid = true;
          break;
        }
      }
    }
    cout << (valid ? "yes" : "no") << endl;
  }

  return 0;
}