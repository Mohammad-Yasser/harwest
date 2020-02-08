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

vector<pair<int, int>> adj[N][4];

bool vis[N][4];

void dfs(int ind, int border) {
  stack<pair<int, int>> st;
  st.emplace(ind, border);
  while (!st.empty()) {
    auto curr = st.top();
    st.pop();
    if (vis[curr.first][curr.second]) continue;
    vis[curr.first][curr.second] = true;
    for (auto& v : adj[curr.first][curr.second]) {
      st.emplace(v);
    }
  }
}

int n, m;

void connect_corners() {
  adj[1][left_border].emplace_back(1, up_border);
  adj[n][left_border].emplace_back(1, down_border);

  adj[1][right_border].emplace_back(m, up_border);
  adj[n][right_border].emplace_back(m, down_border);

  adj[1][up_border].emplace_back(1, left_border);
  adj[m][up_border].emplace_back(1, right_border);

  adj[1][down_border].emplace_back(n, left_border);
  adj[m][down_border].emplace_back(n, right_border);
}

int solve() {

  connect_corners();

  for (int q = 0; q < 2; ++q) {
    for (int i = 1; i <= n; ++i) {
      int x = i;
      // Go up
      if (x <= m) {
        // Hit the upper border
        adj[i][left_border].emplace_back(x, up_border);
        adj[i][right_border].emplace_back(m - x + 1, up_border);
      } else {
        // Hit the opposite border
        adj[i][left_border].emplace_back(x - m + 1, right_border);
        adj[i][right_border].emplace_back(x - m + 1, left_border);
      }

      x = n - i + 1;
      // Go down
      if (x <= m) {
        // Hit the lower border
        adj[i][left_border].emplace_back(x, down_border);
        adj[i][right_border].emplace_back(m - x + 1, down_border);
      } else {
        // Hit the opposite border
        adj[i][left_border].emplace_back(i + m - 1, right_border);
        adj[i][right_border].emplace_back(i + m - 1, left_border);
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

void clear() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j <= max(n, m); ++j) {
      adj[i][j].clear();
      vis[i][j] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> m;
  cout << solve() << endl;

  return 0;
}
