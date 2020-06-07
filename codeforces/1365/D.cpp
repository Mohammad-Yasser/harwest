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

const int N = 51;

char grid[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool valid(int x, int y) {
  return min(x, y) >= 0 && x < n && y < m && grid[x][y] != '#';
}

int dfs(int x, int y) {
  if (!valid(x, y)) return 0;
  int res = (grid[x][y] == 'G');
  grid[x][y] = '#';
  for (int d = 0; d < 4; ++d) {
    int i = x + dx[d];
    int j = y + dy[d];
    res += dfs(i, j);
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

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> m;
    int cnt_good = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
        cnt_good += (grid[i][j] == 'G');
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 'B') continue;
        for (int d = 0; d < 4; ++d) {
          int x = i + dx[d];
          int y = j + dy[d];
          if (grid[x][y] != 'B' && valid(x, y)) {
            grid[x][y] = '#';
          }
        }
      }
    }
    cnt_good -= dfs(n - 1, m - 1);
    if (cnt_good == 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}