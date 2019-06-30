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

const int N = 1e3 + 5;

bool must_be_less[N];

vector<pair<int, int>> unsorted;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  while (m--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      for (int i = l; i < r; ++i) {
        must_be_less[i] = true;
      }
    } else {
      unsorted.emplace_back(l, r);
    }
  }

  for (auto& pr : unsorted) {
    if (*min_element(must_be_less + pr.first, must_be_less + pr.second) != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  int last = 1e5;
  for (int i = 1 ; i <= n ; ++i) {
    cout << last << " ";
    last -= !must_be_less[i];
  }

}
