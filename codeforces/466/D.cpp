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

const int N = 2005;
const int MOD = 1000000007;
int memo[N][N];

int arr[N];

int h;
int n;
int solve(int ind, int open) {
  if (open >= N) return 0;
  if (ind == n) return open == 0;
  int& res = memo[ind][open];
  if (res != -1) return res;

  if (arr[ind] + open > h) {
    res = 0;
  } else if (arr[ind] + open < h - 1) {
    res = 0;
  } else if (arr[ind] + open == h - 1) {
    res = (solve(ind + 1, open + 1) + 1LL * solve(ind + 1, open) * (open + 1)) %
          MOD;
  } else {
    res = 0;
    if (open > 0) {
      res = 1LL * solve(ind + 1, open - 1) * open % MOD;
    }
    res = (res + solve(ind + 1, open)) % MOD;
  }
  // cout << ind << " " << open << " " << res << endl;
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
  cin >> n >> h;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  assert(solve(0, 0) >= 0 && solve(0, 0) < MOD);
  cout << solve(0, 0) << endl;
  return 0;
}