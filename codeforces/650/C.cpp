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

const int N = 1e6 + 5;
vector<vector<pair<int, int>>> rows, cols;
int grid[N];
int n, m;
int getInd(int i, int j) { return i * m + j; }

vector<int> adj[N];

struct DSU {
  int parent[N];
  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }
  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }
  void join(int x, int y) {
    x = getRoot(x);
    y = getRoot(y);
    parent[x] = y;
  }
} dsu;

int memo[N];

int solve(int ind) {
  int& res = memo[ind];
  if (res != -1) return res;
  res = 1;
  for (int v : adj[ind]) {
    res = max(res, solve(v) + 1);
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

  memset(memo, -1, sizeof memo);
  dsu.init();

  cin >> n >> m;
  rows.resize(n);
  cols.resize(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      int ind = getInd(i, j);
      rows[i].emplace_back(x, ind);
      cols[j].emplace_back(x, ind);
    }
  }

  for (int s = 0; s < 2; ++s) {
    for (auto& row : rows) {
      sort(rall(row));
      for (int j = 0; j + 1 < sz(row); ++j) {
        if (row[j].first == row[j + 1].first) {
          dsu.join(row[j].second, row[j + 1].second);
        } else {
          adj[row[j].second].emplace_back(row[j + 1].second);
        }
      }
    }
    swap(rows, cols);
  }

  for (int i = 0; i < N; ++i) {
    if (dsu.parent[i] == i) continue;
    int j = dsu.getRoot(i);
    adj[j].insert(end(adj[j]), all(adj[i]));
  }

  for (int i = 0; i < N; ++i) {
    if (dsu.parent[i] != i) continue;
    for (int& x : adj[i]) {
      x = dsu.getRoot(x);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << solve(dsu.getRoot(getInd(i, j))) << " ";
    }
    cout << endl;
  }

  return 0;
}