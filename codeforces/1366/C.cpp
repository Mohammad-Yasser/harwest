#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 31;
int n, m;
bool grid[N][N];

vector<vector<pair<int, int>>> cells_dist;

struct DSU {
  const static int SZ = N * N;
  int parent[SZ];
  int cnt[SZ][2];
  void init() {
    for (int i = 0; i < SZ; ++i) {
      parent[i] = i;
      cnt[i][0] = cnt[i][1] = 0;
    }
  }
  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }
  void join(int x, int y) {
    x = getRoot(x);
    y = getRoot(y);
    if (x == y) return;
    cnt[y][0] += cnt[x][0];
    cnt[y][1] += cnt[x][1];
    parent[x] = y;
  }
} dsu;

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
    dsu.init();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
        if (grid[i][j]) {
          ++dsu.cnt[i * m + j][1];
        } else {
          ++dsu.cnt[i * m + j][0];
        }
      }
    }
    cells_dist.clear();
    cells_dist.resize(n + m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int d = i + j;
        cells_dist[d].emplace_back(i, j);
      }
    }
    for (int ld = 0, rd = n + m - 2; ld < rd; ++ld, --rd) {
      for (auto& x : cells_dist[ld]) {
        for (auto& y : cells_dist[rd]) {
          if (x.first <= y.first && x.second <= y.second) {
            dsu.join(x.first * m + x.second, y.first * m + y.second);
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < dsu.SZ; ++i) {
      if (dsu.parent[i] != i) continue;
      res += min(dsu.cnt[i][0], dsu.cnt[i][1]);
    }
    cout << res << endl;
  }

  return 0;
}