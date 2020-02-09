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

const int N = 1e6 + 3;

int left_border = 0, right_border = 1;
int up_border = 2, down_border = 3;

pair<int, int> adj[N][4][2];

bool vis[N][4];
vector<pair<int, int>> st;

void emplaceAdj(int a, int b, int c, int d) {
  if (adj[a][b][0].first == -1) {
    adj[a][b][0] = make_pair(c, d);
  } else {
    adj[a][b][1] = make_pair(c, d);
  }
}

void dfs(int ind, int border) {
  st.emplace_back(ind, border);
  while (!st.empty()) {
    auto curr = st.back();
    st.pop_back();
    if (vis[curr.first][curr.second]) continue;
    vis[curr.first][curr.second] = true;
    for (auto& v : adj[curr.first][curr.second]) {
      if (v.first != -1) {
        st.emplace_back(v);
      }
    }
  }
}

int n, m;

void connect_corners() {
  for (int q = 0; q < 2; ++q) {
    emplaceAdj(1, left_border, 1, up_border);
    emplaceAdj(n, left_border, 1, down_border);

    emplaceAdj(1, right_border, m, up_border);
    emplaceAdj(n, right_border, m, down_border);

    swap(n, m);
    swap(left_border, up_border);
    swap(right_border, down_border);
  }
}

int solve() {

  connect_corners();

  for (int q = 0; q < 2; ++q) {
    for (int i = 1; i <= n; ++i) {
      int x = i;
      // Go up
      if (x <= m) {
        // Hit the upper border
        emplaceAdj(i, left_border, x, up_border);
        emplaceAdj(i, right_border, m - x + 1, up_border);
      } else {
        // Hit the opposite border
        emplaceAdj(i, left_border, x - m + 1, right_border);
        emplaceAdj(i, right_border, x - m + 1, left_border);
      }

      x = n - i + 1;
      // Go down
      if (x <= m) {
        // Hit the lower border
        emplaceAdj(i, left_border, x, down_border);
        emplaceAdj(i, right_border, m - x + 1, down_border);
      } else {
        // Hit the opposite border
        emplaceAdj(i, left_border, i + m - 1, right_border);
        emplaceAdj(i, right_border, i + m - 1, left_border);
      }
    }
    swap(n, m);
    swap(left_border, up_border);
    swap(right_border, down_border);
  }

  int res = 0;

  for (int q = 0; q < 2; ++q) {
    for (int i = 1; i <= n; ++i) {
      if (!vis[i][left_border]) {
        ++res;
        dfs(i, left_border);
      }
      if (!vis[i][right_border]) {
        ++res;
        dfs(i, right_border);
      }
    }
    swap(n, m);
    swap(left_border, up_border);
    swap(right_border, down_border);
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

  st.reserve(4 * N);
  memset(adj, -1, sizeof adj);

  cin >> n >> m;
  cout << solve() << endl;

  return 0;
}
