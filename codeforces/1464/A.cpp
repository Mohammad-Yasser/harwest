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

const int N = 1e5 + 5;
int vis[N];
int vis_id;
vector<int> row;

int dfs(int r) {
  if (vis[r] == vis_id) return 1;
  vis[r] = vis_id;
  if (row[r] == -1 || row[r] == r) return 0;
  int res = 1 + dfs(row[r]);
  row[r] = -1;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    row.assign(n, -1);
    while (m--) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      row[x] = y;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (row[i] != -1) {
        ++vis_id;
        res += dfs(i);
      }
    }
    cout << res << endl;
  }
  return 0;
}