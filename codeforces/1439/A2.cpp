#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

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
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 101;

string grid[N];

struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
};

vector<Point> ops;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;
  while (t--) {
    ops.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
      for (char& x : grid[i]) x -= '0';
    }
    for (int i = 0; i + 1 < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i + 2 == n) {
          if (j % 2 == 1 && j + 2 != m) continue;
          if (j + 3 == m) {
            for (int dx = 0; dx < 2; ++dx) {
              if (grid[i + dx][j]) {
                grid[i][j + 1] ^= 1;
                grid[i + 1][j + 1] ^= 1;
                ops.emplace_back(i + dx, j);
                ops.emplace_back(i, j + 1);
                ops.emplace_back(i + 1, j + 1);
              }
            }
            continue;
          }
          vector<Point> ones, zeroes;

          for (int dx = 0; dx < 2; ++dx) {
            for (int dy = 0; dy < 2; ++dy) {
              if (grid[i + dx][j + dy]) {
                ones.emplace_back(i + dx, j + dy);
                grid[i + dx][j + dy] = 0;
              } else {
                zeroes.emplace_back(i + dx, j + dy);
              }
            }
          }

          if (sz(ones) == 4) {
            for (int dx = 0; dx < 2; ++dx) {
              for (int dy = 0; dy < 2; ++dy) {
                if (make_pair(dx, dy) != make_pair(0, 0)) {
                  ops.emplace_back(i, j);
                }
                if (make_pair(dx, dy) != make_pair(0, 1)) {
                  ops.emplace_back(i, j + 1);
                }
                if (make_pair(dx, dy) != make_pair(1, 0)) {
                  ops.emplace_back(i + 1, j);
                }
                if (make_pair(dx, dy) != make_pair(1, 1)) {
                  ops.emplace_back(i + 1, j + 1);
                }
              }
            }
            continue;
          }
          if (sz(ones) == 3) {
            ops.insert(end(ops), all(ones));
            continue;
          }
          if (sz(ones) == 2) {
            for (int i = 0; i < 2; ++i) {
              ops.emplace_back(ones[i]);
              ops.emplace_back(zeroes[0]);
              ops.emplace_back(zeroes[1]);
            }
            continue;
          }
          if (sz(ones) == 1) {
            ops.emplace_back(ones[0]);
            ops.emplace_back(zeroes[0]);
            ops.emplace_back(zeroes[2]);
            swap(ones[0], zeroes[0]);
            ones.emplace_back(zeroes[2]);
            zeroes.pop_back();
            for (int i = 0; i < 2; ++i) {
              ops.emplace_back(ones[i]);
              ops.emplace_back(zeroes[0]);
              ops.emplace_back(zeroes[1]);
            }
            continue;
          }
          continue;
        }
        if (grid[i][j]) {
          ops.emplace_back(i, j);
          ops.emplace_back(i + 1, j + (j + 1 != m) - (j + 1 == m));
          grid[ops.back().x][ops.back().y] ^= 1;
          ops.emplace_back(i + 1, j);
          grid[ops.back().x][ops.back().y] ^= 1;
        }
      }
    }
    cout << sz(ops) / 3 << endl;
    for (auto& p : ops) {
      cout << p.x + 1 << " " << p.y + 1 << endl;
    }
    cout << endl;
  }
  return 0;
}