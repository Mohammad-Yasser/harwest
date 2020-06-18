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
typedef unsigned long long Long;
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

const int N = 2e5 + 5;

vector<int> adj[N];
vector<int> parents[N];
int cnt_parents[N];
bool removed[N];
int n;

void init() {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
    parents[i].clear();
    cnt_parents[i] = 0;
    removed[i] = false;
  }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> solve() {
  static vector<int> res;
  static vector<int> perm;
  perm.clear();
  res.clear();
  for (int i = 1; i <= n; ++i) {
    removed[i] = false;
    perm.emplace_back(i);
  }
  shuffle(all(perm), rng);

  for (int i : perm) {
    if (removed[i]) continue;
    for (int child : adj[i]) {
      if (removed[child]) continue;
      for (int grand : adj[child]) {
        if (removed[grand]) continue;
        res.emplace_back(grand);
        removed[grand] = true;
      }
    }
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
  vector<int> res;
  while (t--) {
    res.clear();
    int m;
    cin >> n >> m;
    init();
    while (m--) {
      int u, v;
      cin >> u >> v;
      adj[u].emplace_back(v);
      ++cnt_parents[v];
      parents[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
      bool to_remove = false;
      for (int parent : parents[i]) {
        if (cnt_parents[parent] == 0 || removed[parent]) continue;
        to_remove = true;
        break;
      }
      if (!to_remove) continue;
      res.emplace_back(i);
      removed[i] = true;
      for (int v : adj[i]) {
        --cnt_parents[v];
      }
    }
    for (int i = 0; i < 30; ++i) {
      auto tmp = solve();
      if (tmp.size() < res.size()) {
        swap(res, tmp);
      }
    }
    cout << res.size() << endl;
    cout << res << endl;
  }
  return 0;
}