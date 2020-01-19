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

const Long OO = 1e17;

Long mul(Long x, Long a) {
  if (x > OO / a) return OO;
  return x * a;
}

Long add(Long x, Long a) {
  return min(OO, x + a);
}

Long x_0, y_0, ax, ay, bx, by;

vector<pair<Long, Long>> getDataNodes() {
  Long curr_x = x_0;
  Long curr_y = y_0;
  vector<pair<Long, Long>> res;
  while (curr_x < OO && curr_y < OO) {
    res.emplace_back(curr_x, curr_y);
    curr_x = mul(curr_x, ax);
    curr_x = add(curr_x, bx);

    curr_y = mul(curr_y, ay);
    curr_y = add(curr_y, by);
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

  cin >> x_0 >> y_0 >> ax >> ay >> bx >> by;

  auto data_nodes = getDataNodes();

  Long xs, ys, t;
  cin >> xs >> ys >> t;

  int res = 0;

  for (int i = 0; i < data_nodes.size(); ++i) {
    for (int j = i; j < data_nodes.size(); ++j) {
      Long needed = abs(data_nodes[i].first - data_nodes[j].first)
        + abs(data_nodes[i].second - data_nodes[j].second);
      needed += min(
        abs(data_nodes[i].first - xs) + abs(data_nodes[i].second - ys),
        abs(data_nodes[j].first - xs) + abs(data_nodes[j].second - ys));
      if (needed <= t) {
        res = max(res, j - i + 1);
      }
    }
  }

  cout << res << endl;

}
