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

const int N = 5e5 + 5;

vector<pair<int, int>> initial_sizes;

struct DSU {
  vector<int> parent[N];
  vector<bool> color[N];  // color[i] = ith color ^ parent[i]th color.
  vector<int> rank[N];
  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i].emplace_back(i);
      color[i].emplace_back(false);
      rank[i].emplace_back(1);
    }
  }

  pair<int, int> getRoot(int x) {
    bool c = false;
    while (parent[x].back() != x) {
      c ^= color[x].back();
      x = parent[x].back();
    }
    return make_pair(x, c);
  }

  bool join(int x, int y) {
    bool color_x, color_y;
    tie(x, color_x) = getRoot(x);
    tie(y, color_y) = getRoot(y);
    if (x == y) {
      return color_x != color_y;
    }
    if (rank[x].back() > rank[y].back()) {
      swap(x, y);
    }
    initial_sizes.emplace_back(x, sz(parent[x]));
    initial_sizes.emplace_back(y, sz(parent[y]));
    parent[x].emplace_back(y);
    color[x].emplace_back(color_x ^ color_y ^ 1);
    rank[x].emplace_back(rank[x].back());
    rank[y].emplace_back(max(rank[y].back(), rank[x].back() + 1));
    return true;
  }
} dsu;

vector<int> group[N];
int group_of[N];
bool invalid[N];
map<int, vector<pair<int, int>>> mp[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    int g;
    cin >> g;
    group[g].emplace_back(i);
    group_of[i] = g;
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    int gu = group_of[u];
    int gv = group_of[v];
    if (gu > gv) {
      swap(gu, gv);
      swap(u, v);
    }
    mp[gu][gv].emplace_back(u, v);
  }

  dsu.init();
  int cnt_valid = k;
  for (int i = 1; i <= k; ++i) {
    for (auto [u, v] : mp[i][i]) {
      if (!dsu.join(u, v)) {
        invalid[i] = true;
        --cnt_valid;
        break;
      }
    }
  }
  Long res = 1LL * cnt_valid * (cnt_valid-1)/2;

  for (int i = 1; i <= k; ++i) {
    if (invalid[i]) continue;
    for (auto [to, adj] : mp[i]) {
      if (invalid[to]) {
        continue;
      }
      initial_sizes.clear();
      bool valid = true;
      for (auto [u, v] : adj) {
        if (!dsu.join(u, v)) {
          valid = false;
          break;
        }
      }
      res -= !valid;

      for (auto [x, old_size] : initial_sizes) {
        if (old_size > sz(dsu.parent[x])) continue;
        dsu.parent[x].resize(old_size);
        dsu.rank[x].resize(old_size);
        dsu.color[x].resize(old_size);
      }
    }
  }
  cout << res << endl;

  return 0;
}