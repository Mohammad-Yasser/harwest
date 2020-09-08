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

const int N = 500001;
bool reached[N][2];
string res;
int n;
vector<pair<int, int>> adj[N];
bool vis[N];
int bfs() {
  queue<int> q;
  q.emplace(n);
  vis[n] = true;
  int level = 0;
  while (!q.empty()) {
    int sz = sz(q);
    while (sz--) {
      int curr = q.front();
      q.pop();
      if (curr == 1) return level;
      for (auto [v, color] : adj[curr]) {
        if (vis[v]) continue;
        reached[v][color] = true;
        if (reached[v][color ^ 1]) {
          vis[v] = true;
          q.emplace(v);
        } else {
          res[v - 1] = color ^ '1';
        }
      }
    }
    ++level;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  res = string(n, '0');
  int m;
  cin >> m;
  while (m--) {
    int u, v, t;
    cin >> u >> v >> t;
    adj[v].emplace_back(u, t);
  }
  cout << bfs() << endl;
  cout << res << endl;
  return 0;
}