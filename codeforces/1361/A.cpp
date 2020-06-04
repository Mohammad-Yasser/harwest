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
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

typedef long long Long;
typedef long double Double;
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

const int N = 5e5 + 5;
vector<int> adj[N];
vector<int> used[N];

int getMex(int node) {
  sort(used[node].rbegin(), used[node].rend());
  int res = 1;
  while (!used[node].empty() && used[node].back() <= res) {
    res += (used[node].back() == res);
    used[node].pop_back();
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

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<pair<int, int>> topics;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    topics.emplace_back(x, i);
  }
  sort(all(topics));

  for (auto& p : topics) {
    if (getMex(p.second) != p.first) {
      cout << -1 << endl;
      return 0;
    }
    for (int v : adj[p.second]) {
      used[v].emplace_back(p.first);
    }
  }

  for (auto& p : topics) {
    cout << p.second << " ";
  }

  cout << endl;

  return 0;
}