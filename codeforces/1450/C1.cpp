#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
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

const int N = 303;
char grid[N][N];
int cnt[3][3];

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
    memset(grid, '.', sizeof grid);
    memset(cnt, 0, sizeof cnt);
    int n;
    cin >> n;
    int all = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> grid[i][j];
        if (grid[i][j] == 'X') {
          ++cnt[(i + j) % 3][0];
          ++cnt[(i + j) % 3][2];
          ++all;
        }
        if (grid[i][j] == 'O') {
          ++cnt[(i + j) % 3][1];
          ++cnt[(i + j) % 3][2];
          ++all;
        }
      }
    }
    int to_be_x = -1;
    int to_be_o = -1;
    for (int i = 0; i < 3; ++i) {
      if (cnt[i][2] < (all + 2) / 3) continue;
      int j = (i == 0 ? 1 : 0);
      int k = (i == 2 ? 1 : 2);
      to_be_x = k;
      to_be_o = j;
      if (cnt[j][0] + cnt[k][1] > all / 3) {
        swap(to_be_x, to_be_o);
      }
      break;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (grid[i][j] == '.') {
          cout << '.';
          continue;
        }
        int g = (i + j) % 3;
        if (g == to_be_x) {
          cout << 'X';
        } else if (g == to_be_o) {
          cout << 'O';
        } else {
          cout << grid[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}