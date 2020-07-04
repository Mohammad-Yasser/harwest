#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
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
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 303;

int grid[N][N];
int n, m;

vector<pair<int, int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

bool valid(int i, int j) { return min(i, j) >= 0 && i < n && j < m; }

int countNeighbours(int i, int j) {
  int res = 0;
  for (auto [dx, dy] : dirs) {
    res += valid(i + dx, j + dy);
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
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
      }
    }
    bool invalid = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int tmp = countNeighbours(i, j);
        if (grid[i][j] > tmp) {
          invalid = true;
        }
        grid[i][j] = tmp;
      }
    }

    if (invalid) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << grid[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}