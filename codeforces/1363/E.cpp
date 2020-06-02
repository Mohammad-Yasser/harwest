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
typedef long long Long;
typedef double Double;

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

bool a[N];
bool b[N];

int c[N];

struct State {
  Long cost = 0;
  int ones = 0;
  int zeroes = 0;
  State operator+(const State& other) const {
    State res = (*this);
    res.cost += other.cost;
    res.ones += other.ones;
    res.zeroes += other.zeroes;
    return res;
  }
};

vector<int> adj[N];

State dfs(int node, int parent, int cost) {
  State res;
  for (int v : adj[node]) {
    if (v == parent) continue;
    res = res + dfs(v, node, min(cost, c[v]));
  }
  if (a[node] != b[node]) {
    if (a[node]) {
      ++res.ones;
    } else {
      ++res.zeroes;
    }
  }
  int mn = min(res.ones, res.zeroes);
  res.cost += 2LL * mn * cost;
  res.ones -= mn;
  res.zeroes -= mn;
  return res;
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

  for (int i = 1; i <= n; ++i) {
    cin >> c[i] >> b[i] >> a[i];
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  auto res = dfs(1, -1, c[1]);

  if (res.ones + res.zeroes != 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << res.cost << endl;

  return 0;
}