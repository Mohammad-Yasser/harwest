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

const int N = 5e4 + 5;
vector<int> adj[N];

Long res;
int k;

vector<int> dfs(int node, int parent) {
  vector<vector<int>> children_cnt;
  children_cnt.reserve(sz(adj[node]) - (parent != -1));
  int big_child = -1;
  for (int v : adj[node]) {
    if (parent == v) continue;
    children_cnt.emplace_back(dfs(v, node));
    if (big_child == -1 ||
        sz(children_cnt.back()) > sz(children_cnt[big_child])) {
      big_child = sz(children_cnt) - 1;
    }
  }
  if (big_child == -1) {
    children_cnt.emplace_back(vector<int>());
    big_child = 0;
  }
  auto& curr_cnt = children_cnt[big_child];
  curr_cnt.emplace_back(1);
  if (sz(curr_cnt) >= k + 1) {
    res += curr_cnt[sz(curr_cnt) - k - 1];
  }
  for (int i = 0; i < sz(children_cnt); ++i) {
    if (i == big_child) continue;
    for (int j = 0; j < sz(children_cnt[i]); ++j) {
      int child_depth = sz(children_cnt[i]) - j;
      if (child_depth > k) continue;
      int curr_depth = k - child_depth;
      int curr_idx = sz(curr_cnt) - curr_depth - 1;
      if (curr_idx >= 0) {
        assert(curr_idx < sz(curr_cnt));
        res += 1LL * curr_cnt[curr_idx] * children_cnt[i][j];
      }
    }
    for (int j = 0; j < sz(children_cnt[i]); ++j) {
      assert(sz(curr_cnt) - j - 2 >= 0);
      curr_cnt[sz(curr_cnt) - j - 2] +=
          children_cnt[i][sz(children_cnt[i]) - 1 - j];
    }
  }
  return move(children_cnt[big_child]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  dfs(1, -1);
  cout << res << endl;

  return 0;
}