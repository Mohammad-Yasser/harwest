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

const int N = 1003;
const int OO = 1e9 / 2;

string grid[N];
int dist[N][N];

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool change(int i, int j) {
  for (int d = 0; d < 4; ++d) {
    if (grid[i + dx[d]][j + dy[d]] == grid[i][j]) return true;
  }
  return false;
}

void bfs() {
  queue<pair<int, int>> q;
  memset(dist, -1, sizeof dist);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (change(i, j)) {
        q.emplace(i, j);
        dist[i][j] = 0;
      }
    }
  }
  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      auto nxt = curr;
      nxt.first += dx[d], nxt.second += dy[d];
      if (min(nxt.first, nxt.second) <= 0 || nxt.first > n || nxt.second > m)
        continue;
      if (dist[nxt.first][nxt.second] != -1) continue;
      dist[nxt.first][nxt.second] = dist[curr.first][curr.second] + 1;
      q.emplace(nxt);
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

  int t;
  cin >> n >> m >> t;
  grid[0] = string(m, '!');
  for (int i = 1; i <= n; ++i) {
    cin >> grid[i];
    grid[i] = "!" + grid[i] + "!";
  }
  grid[n + 1] = string(m, '!');

  bfs();

  while (t--) {
    int i, j;
    Long p;
    cin >> i >> j >> p;
    if (dist[i][j] == -1 || p < dist[i][j]) {
      cout << grid[i][j] << endl;
      continue;
    }
    char res = grid[i][j];
    res ^= ((p - dist[i][j]) & 1);
    cout << res << endl;
  }

  return 0;
}