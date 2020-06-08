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

typedef long long Long;
typedef long double Double;

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

const int MOD = 1000000007;

int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}

int modInverse(int x) { return power(x, MOD - 2); }

const int N = 1e5 + 5;

vector<int> adj[N];
bool used[N];
int deg[N];

int n, k;

bool check() {
  vector<int> leaves, nxt_leaves;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) {
      leaves.emplace_back(i);
      used[i] = true;
    } else if (deg[i] < 3)
      return false;
  }
  while (k--) {
    if (leaves.empty()) return false;
    for (int node : leaves) {
      for (int v : adj[node]) {
        if (used[v]) continue;
        --deg[v];
      }
    }
    for (int node : leaves) {
      for (int v : adj[node]) {
        if (used[v]) continue;
        if (k == 0) {
          if (deg[v] != 0) return false;
          if (adj[v].size() < 3) return false;
        } else {
          if (deg[v] != 1) return false;
          if (adj[v].size() < 4) return false;
        }
        nxt_leaves.emplace_back(v);
        used[v] = true;
      }
    }
    leaves = nxt_leaves;
    nxt_leaves.clear();
  }
  return sz(leaves) == 1 && deg[leaves[0]] == 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> k;
  if (n == 1) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    ++deg[u], ++deg[v];
  }
  cout << (check() ? "Yes" : "No") << endl;
  return 0;
}
