#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif
  srand(time(0));
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1));
    vector<int> degree(n + 1);

    int j = 1;
    for (int i = 1; i <= n; ++i) {
      while (degree[i] < 4) {
        while (i == j || adj[i][j] || degree[j] == 4) {
          if (++j > n) j = 1;
        }
        adj[i][j] = adj[j][i] = true;
        cout << i << " " << j << endl;
        ++degree[i], ++degree[j];
        if (++j > n) j = 1;
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (!adj[i][j] && p > 0) {
          --p;
          cout << i << " " << j << endl;
          adj[i][j] = adj[j][i] = true;
        }
      }
    }
  }
  return 0;
}