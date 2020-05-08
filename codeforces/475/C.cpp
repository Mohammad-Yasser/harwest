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

template <typename T>
void minimize(T& x, const T& y) {
  x = min(x, y);
}

template <typename T>
void maximize(T& x, const T& y) {
  x = max(x, y);
}

typedef long long Long;
constexpr int N = 2003;

vector<vector<char>> grid(N, vector<char>(N, '.'));

int first_x[N];
int last_x[N];
int cnt_x[N];
int total_cnt_x;
int first_row;
int last_row;
int n, m;

template <typename T>
vector<vector<T>> transpose(const vector<vector<T>>& grid) {
  int length = grid[0].size();
  int width = grid.size();

  vector<vector<T>> res(length, vector<T>(width));
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      res[i][j] = grid[j][i];
    }
  }
  return res;
}

template <typename T>
void print(const vector<T>& v, const string& sep = "\n") {
  for (auto& x : v) {
    cout << x << sep;
  }
  cout.flush();
}

template <typename T>
void print(const vector<vector<T>>& v) {
  for (auto& x : v) {
    print(x, "");
    cout << endl;
  }
  cout.flush();
}

char hyp[N][N];
void print() {
  for (int i = 0; i <= n + 1; ++i) {
    for (int j = 0; j <= m + 1; ++j) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

bool valid(int width, int length) {
  memset(hyp, '.', sizeof hyp);
  for (int i = first_row; i < first_row + length; ++i) {
    for (int j = first_x[first_row]; j < first_x[first_row] + width; ++j) {
      hyp[i][j] = 'X';
    }
  }
  int y = first_x[first_row];
  for (int x = first_row + 1;; ++x) {
    if (cnt_x[x + length - 1] == 0) break;
    for (int j = y; j < y + width; ++j) {
      hyp[x + length - 1][j] = 'X';
    }
    int nxt_y = y;
    while (nxt_y + width <= last_x[x]) ++nxt_y;
    for (int i = x; i < x + length; ++i) {
      for (int j = y; j < nxt_y; ++j) {
        hyp[i][j + width] = 'X';
      }
    }
    y = nxt_y;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (hyp[i][j] != grid[i][j]) return false;
    }
  }
  return true;
}

int solve() {
  if (last_x[first_row] - first_x[first_row] + 1 == total_cnt_x) return 1;
  int length = last_x[first_row] - first_x[first_row] + 1;
  int width = 0;
  for (int i = first_row + 1; i <= n + 1; ++i) {
    if (last_x[i] != last_x[i - 1] && width == 0) {
      width -= i;
    }
    if (first_x[i] != first_x[i - 1] && width < 0) {
      width += i;
    }
  }
  width = max(width, 1);
  if (!valid(length, width)) return 1e9;
  return 1LL * length * width;
}

void build() {
  first_row = 1e9;
  last_row = 0;
  total_cnt_x = 0;
  memset(first_x, 0, sizeof first_x);
  memset(last_x, 0, sizeof last_x);
  memset(cnt_x, 0, sizeof cnt_x);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j] == 'X') {
        ++total_cnt_x;
        first_row = min(first_row, i);
        last_row = i;
        if (!first_x[i]) {
          first_x[i] = j;
        }
        last_x[i] = j;
        ++cnt_x[i];
      }
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
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
    }
  }

  build();
  int res = 1e9;
  res = min(res, solve());
  swap(n, m);
  grid = transpose(grid);
  build();
  res = min(res, solve());
  if (res == 1e9) res = -1;
  cout << res << endl;
  return 0;
}