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

const int N = 1e6 + 5;
Long d;
Long a[N];
Long pistol, laser, awp;
Long memo[N][2][2];
int n;

Long solve(int ind, bool go_back, bool end_back) {
  Long& res = memo[ind][go_back][end_back];
  if (res != -1) return res;
  res = LLONG_MAX;

  // Use AWP
  if (!go_back) {
    res = min(res, pistol * a[ind] + awp +
                       +(ind == n - 1 ? 0 : d + solve(ind + 1, false, false)));
  } else {
    res = min(
        res, pistol * a[ind] + awp +
                 (ind == n - 1 ? d
                               : min(3 * d + solve(ind + 1, end_back, end_back),
                                     2 * d + solve(ind + 1, true, true))));
  }

  // Use pistol or laser
  Long go_left = LLONG_MAX, go_right = LLONG_MAX;
  if (ind != 0) {
    go_left = 2 * d +
              (ind == n - 1 ? 0 : d + solve(ind + 1, end_back, end_back)) +
              d * end_back;
  }
  if (ind != n - 1) {
    go_right = d + solve(ind + 1, true, go_back) + d * go_back;
  }
  // Pistol
  res = min(res, pistol * (a[ind] + 2) + min(go_left, go_right));
  // Laser
  res = min(res, laser + pistol + min(go_left, go_right));
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo, -1, sizeof memo);
  cin >> n;
  cin >> pistol >> laser >> awp;
  pistol = min(pistol, awp);
  cin >> d;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(0, false, false) << endl;
  return 0;
}