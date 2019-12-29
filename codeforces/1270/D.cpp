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

int ask(const vector<int>& query) {
  cout << "? ";
  for (int x : query) {
    cout << x << " ";
  }
  cout << endl;
  int x;
  cin >> x >> x;
  return x;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
//  freopen("test.in", "r", stdin);
#else
//#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  n = k + 1;
  map<int, int> cnt;
  for (int i = 1; i <= n; ++i) {
    vector<int> query;
    for (int j = 1; j <= n; ++j) {
      if (i != j) {
        query.emplace_back(j);
      }
    }
    ++cnt[ask(query)];
  }
  cout << "! " << cnt.rbegin()->second << endl;

}
