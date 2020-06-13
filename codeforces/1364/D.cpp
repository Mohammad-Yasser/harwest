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
#define rall(v) rbegin(v), rend(v)
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

typedef long long Long;
typedef double Double;
typedef vector<int> vi;

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

const int N = 1e5 + 5;

bool vis[N];
int parent[N];
int k;

vector<int> adj[N];

void printCycle(int start, int end) {
  vi res;
  res.emplace_back(start);
  do {
    res.emplace_back(parent[res.back()]);
  } while (res.back() != end);
  cout << 2 << endl;
  cout << sz(res) << endl;
  cout << res << endl;
  exit(0);
}

vector<int> path;
void printIndependentSet() {
  memset(vis, 0, sizeof vis);
  vector<int> res;
  while (!path.empty()) {
    int curr = path.back();
    path.pop_back();
    if (vis[curr]) continue;
    vis[parent[curr]] = true;
    res.emplace_back(curr);
  }
  cout << 1 << endl;
  while (res.size() > (k + 1) / 2) {
    res.pop_back();
  }
  cout << res << endl;
  exit(0);
}

void dfs(int node) {
  static int cnt = 0;
  ++cnt;
  vis[node] = true;
  path.emplace_back(node);
  for (int v : adj[node]) {
    if (v == parent[node]) continue;
    if (vis[v]) {
      printCycle(node, v);
    }
  }
  if (cnt == k) printIndependentSet();
  for (int v : adj[node]) {
    if (vis[v]) continue;
    parent[v] = node;
    dfs(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m >> k;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v), adj[v].emplace_back(u);
  }
  dfs(1);
  printIndependentSet();
  return 0;
}