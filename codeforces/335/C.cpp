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

const int N = 105;

int grundy[N][N][3][3];

bool vis[N][2];

bool isSet(int mask, int bit) { return (mask >> bit) & 1; }

int getMex(vector<int> v) {
  sort(all(v));
  int res = 0;
  while (binary_search(all(v), res)) ++res;
  return res;
}

int solve(int l, int r, int state_l, int state_r) {
  if (r < l) return 0;
  int& res = grundy[l][r][state_l][state_r];
  if (res != -1) return res;
  res = 0;
  vector<int> children;
  for (int i = l; i <= r; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (vis[i][j]) continue;
      if (i == l && isSet(state_l, j)) continue;
      if (i == r && isSet(state_r, j)) continue;
      int sg1 = solve(l, i - 1, state_l, (1 << !j));
      int sg2 = solve(i + 1, r, (1 << !j), state_r);
      children.emplace_back(sg1 ^ sg2);
    }
  }
  res = getMex(children);

  // cout << l << " " << r << " " << state_l << " " << state_r << " " << res
  //      << endl;
  // cout << children << endl;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int r, n;
  cin >> r >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    --b;
    vis[a][b] = true;
    vis[a][b ^ 1] = true;
    vis[a - 1][b ^ 1] = vis[a + 1][b ^ 1] = true;
  }

  memset(grundy, -1, sizeof grundy);

  string ans[] = {"WIN", "LOSE"};
  cout << ans[solve(1, r, 0, 0) == 0] << endl;

  return 0;
}