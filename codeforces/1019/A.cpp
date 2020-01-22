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

const int N = 3001;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  vector<vector<int>> parties(m + 1);

  while (n--) {
    int p, c;
    cin >> p >> c;
    parties[p].emplace_back(c);
  }

  for (auto& party : parties) {
    sort(party.begin(), party.end());
  }

  Long res = LLONG_MAX;

  for (int i = 1; i < N; ++i) {
    int cnt = parties[1].size();
    Long cost = 0;
    priority_queue<int> unused;

    for (int p = 2; p <= m; ++p) {
      auto& party = parties[p];
      for (int j = 0; j < party.size(); ++j) {
        if (j <= (int) party.size() - i) {
          ++cnt;
          cost += party[j];
        } else {
          unused.emplace(party[j]);
          while (unused.size() > i - cnt) {
            unused.pop();
          }
        }
      }
    }

    while (cnt < i && !unused.empty()) {
      ++cnt;
      cost += unused.top();
      unused.pop();
    }

    if (cnt >= i) {
      res = min(res, cost);
    }
  }

  cout << res << endl;

}
