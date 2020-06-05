#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

typedef long long Long;
typedef long double Double;
typedef vector<int> vi;
typedef pair<int, int> pii;

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

// https://github.com/kth-competitive-programming/kactl/blob/master/content/graph/EulerWalk.h
vector<pii> eulerWalk(vector<vector<pii>>& gr, int nedges, int src = -1) {
  int n = sz(gr);
  if (src == -1) {
    src = find_if(all(gr), [](const vector<pii>& v) { return !v.empty(); }) -
          begin(gr);
    if (src == n) return {};
  }

  vi D(n), its(n), eu(nedges);
  vector<pii> s = {make_pair(src, -1)};
  vector<pii> ret;
  D[src]++;  // to allow Euler paths, not just cycles
  while (!s.empty()) {
    auto x = s.back();
    int y, e, &it = its[x.first], end = sz(gr[x.first]);
    if (it == end) {
      ret.emplace_back(x);
      s.pop_back();
      continue;
    }
    tie(y, e) = gr[x.first][it++];
    if (!eu[e]) {
      D[x.first]--, D[y]++;
      eu[e] = 1;
      s.emplace_back(y, e);
    }
  }
  for (int x : D)
    if (x < 0) return {};
  if (sz(ret) != nedges + 1) return {};
  reverse(all(ret));
  return ret;
}

const int N = (1 << 20) + 1;
vector<vector<pii>> graph(N);
vector<pii> cycle;

bool valid(int k, const vector<pii>& pearls) {
  graph.clear();
  graph.resize((1 << k));
  for (int i = 0; i < sz(pearls); ++i) {
    int u = (pearls[i].first & ((1 << k) - 1));
    int v = (pearls[i].second & ((1 << k) - 1));
    graph[u].emplace_back(v, i);
    graph[v].emplace_back(u, i);
  }
  cycle = eulerWalk(graph, pearls.size());
  return !cycle.empty() && cycle.back().first == cycle[0].first;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> pearls(n);
  for (auto& p : pearls) {
    cin >> p.first >> p.second;
  }

  int res = 20;
  while (!valid(res, pearls)) {
    --res;
  }

  cout << res << endl;
  for (int i = 0; i < n; ++i) {
    int u = (pearls[i].first & ((1 << res) - 1));
    int v = (pearls[i].second & ((1 << res) - 1));
    pearls[i] = make_pair(u, v);
  }

  for (int i = 1; i <= n; ++i) {
    auto curr = cycle[i];
    int prev_node = cycle[i - 1].first;
    int curr_edge = curr.second;
    if (pearls[curr_edge].first == prev_node &&
        pearls[curr_edge].second == curr.first) {
      cout << 2 * curr_edge + 1 << " " << 2 * curr_edge + 2 << " ";
    } else {
      cout << 2 * curr_edge + 2 << " " << 2 * curr_edge + 1 << " ";
    }
  }

  cout << endl;

  return 0;
}