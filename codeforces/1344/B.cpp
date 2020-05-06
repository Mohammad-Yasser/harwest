#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

template <typename T>
void minimize(T& x, const T& y) {
  x = min(x, y);
}

template <typename T>
void maximize(T& x, const T& y) {
  x = max(x, y);
}

typedef long long Long;

const int N = 1003;

int row_cnt_hashes[N];
int col_cnt_hashes[N];

int row_state[N];
int col_state[N];

int getNextState(int curr, char c) {
  if (curr == 0) {
    if (c == '#') return 1;
    return 0;
  }
  if (curr == 1) {
    if (c == '#') return 1;
    return 2;
  }
  if (c == '#') return -1;
  return 2;
}

bool vis[N][N];
char grid[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
void dfs(int i, int j) {
  if (min(i, j) < 0 || i >= n || j >= m) return;
  if (grid[i][j] != '#') return;
  grid[i][j] = '!';
  for (int d = 0; d < 4; ++d) {
    dfs(i + dx[d], j + dy[d]);
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
  bool valid = true;
  int empty_rows = n, empty_cols = m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char& c = grid[i][j];
      cin >> c;
      row_state[i] = getNextState(row_state[i], c);
      col_state[j] = getNextState(col_state[j], c);
      valid &= (row_state[i] != -1);
      valid &= (col_state[j] != -1);
      row_cnt_hashes[i] += (c == '#');
      col_cnt_hashes[j] += (c == '#');
      if (c == '#') {
        empty_rows -= (row_cnt_hashes[i] == 1);
        empty_cols -= (col_cnt_hashes[j] == 1);
      }
    }
  }

  if ((empty_rows == 0) != (empty_cols == 0)) {
    valid = false;
  }

  if (!valid) {
    cout << -1 << endl;
    return 0;
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        ++res;
        dfs(i, j);
      }
    }
  }

  cout << res << endl;
  return 0;
}
