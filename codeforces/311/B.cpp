#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, a, b) for (int i = a; i < (b); ++i)

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

const int N = 1e5 + 5;

Long dp[2][N];
Long hill_dist[N];
Long cat_time[N];

void solve(bool curr_row, int curr_l, int curr_r, int prev_l, int prev_r) {
  bool prev_row = !curr_row;
  int mid = (curr_l + curr_r) / 2;
  Long& res = dp[curr_row][mid];
  res = LLONG_MAX;
  int a_mid = prev_l;
  for (int i = prev_l; i <= min(mid, prev_r); ++i) {
    if (dp[prev_row][i] == -1) continue;
    Long tmp = (mid - i) * cat_time[mid] + dp[prev_row][i];
    if (tmp < res) {
      res = tmp;
      a_mid = i;
    }
  }
  if (curr_l < mid) {
    solve(curr_row, curr_l, mid - 1, prev_l, a_mid);
  }
  if (mid < curr_r) {
    solve(curr_row, mid + 1, curr_r, a_mid, prev_r);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 2; i <= n; ++i) {
    cin >> hill_dist[i];
    hill_dist[i] += hill_dist[i - 1];
  }
  Long res = 0;
  for (int i = 1; i <= m; ++i) {
    int h, t;
    cin >> h >> t;
    cat_time[i] = t - hill_dist[h];
    res -= cat_time[i];
  }
  sort(cat_time + 1, cat_time + m + 1);
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= p; ++i) {
    bool curr = (i & 1);
    bool prev = !curr;
    solve(curr, 0, m, 0, m);
  }

  res += dp[p & 1][m];
  cout << res << endl;

  return 0;
}