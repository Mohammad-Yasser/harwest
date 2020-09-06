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

int n, a, b, da, db;

const int N = 1e5 + 5;

vector<int> adj[N];
int dist[N];

pair<int, int> getFurthestLeaf(int node, int parent, int depth) {
  dist[node] = depth;
  pair<int, int> res(depth, node);
  for (int v : adj[node]) {
    if (v == parent) continue;
    auto tmp = getFurthestLeaf(v, node, depth + 1);
    res = max(res, tmp);
  }
  return res;
}

bool solve() {
  if (db <= 2 * da) {
    return true;
  }

  int endpoint1 = getFurthestLeaf(a, -1, 0).second;
  if (dist[b] <= da) return true;
  int d = getFurthestLeaf(endpoint1, -1, 0).first;

  return (d + 1) / 2 <= da;
}

void init() {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
  }
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
    cin >> n >> a >> b >> da >> db;
    init();
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    cout << (solve() ? "Alice" : "Bob") << endl;
  }
  return 0;
}