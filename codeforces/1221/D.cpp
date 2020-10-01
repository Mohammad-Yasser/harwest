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

const int N = 3e5 + 5;
const int K = 3;
const Long OO = LLONG_MAX / 3;
int a[N];
int b[N];
Long memo[N][K];
int vis[N][K];
int vis_id;

int n;
Long solve(int ind, int k) {
  if (ind == n) return 0;
  auto& res = memo[ind][k];
  if (vis[ind][k] == vis_id) return res;
  vis[ind][k] = vis_id;
  res = OO;
  for (int i = 0; i < K; ++i) {
    if (ind == 0 || a[ind] + i != a[ind - 1] + k) {
      res = min(res, solve(ind + 1, i) + 1LL * i * b[ind]);
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

  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    ++vis_id;
    cout << solve(0, 0) << endl;
  }
  return 0;
}