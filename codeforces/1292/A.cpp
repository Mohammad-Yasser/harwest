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

set<int> st[2];

bool isBlocked(int i, int j) {
  auto nxt = st[!i].lower_bound(j + i);
  return nxt != st[!i].end() && *nxt - j <= 1;
}

vector<pair<int, int>> getNeighbours(int j) {
  vector<pair<int, int>> res;
  for (int i = 0; i < 2; ++i) {
    auto nxt = st[i].lower_bound(j);
    if (nxt != st[i].end() && *nxt == j) {
      res.emplace_back(i, j);
    }
    if (nxt != st[i].begin()) {
      --nxt;
      res.emplace_back(i, *nxt);
    }
  }
  return res;
}

int cntBlockages(const vector<pair<int, int>>& v) {
  int res = 0;
  for (auto& p : v) {
    res += isBlocked(p.first, p.second);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int cnt_blockages = 0;
  int n, q;
  cin >> n >> q;
  while (q--) {
    int i, j;
    cin >> i >> j;
    --i;
    auto neighbours = getNeighbours(j);
    cnt_blockages -= cntBlockages(neighbours);
    if (st[i].count(j)) {
      st[i].erase(j);
    } else {
      st[i].insert(j);
    }
    neighbours = getNeighbours(j);
    cnt_blockages += cntBlockages(neighbours);
    cout << (cnt_blockages > 0 ? "NO" : "YES") << endl;
  }

}
