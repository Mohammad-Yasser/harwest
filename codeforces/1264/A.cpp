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

const int N = 1e6 + 5;
int cnt[N];

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
    cin >> n;
    vector<int> p(n);
    vector<int> distinct;
    for (int& x : p) {
      cin >> x;
      ++cnt[x];
      if (distinct.empty() || x != distinct.back()) {
        distinct.push_back(x);
      }
    }

    int g = cnt[p[0]];
    reverse(distinct.begin(), distinct.end());
    distinct.pop_back();
    int s = 0;
    while (!distinct.empty() && s <= g) {
      s += cnt[distinct.back()];
      distinct.pop_back();
    }
    int b = 0;
    while (!distinct.empty() && g + s + b + cnt[distinct.back()] <= n / 2) {
      b += cnt[distinct.back()];
      distinct.pop_back();
    }

    if (s == 0 || b == 0 || g >= s || g >= b || g + s + b > n / 2) {
      cout << "0 0 0" << endl;
    } else {
      cout << g << " " << s << " " << b << endl;
    }

    for (int x : p) {
      cnt[x] = 0;
    }
  }

}
