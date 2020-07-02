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

const int N = 1e5 + 5;
const int K = 201;
const int MOD = 998244353;
int arr[N];

int memo[N][K][2];
int n;

int solve(int ind, int prev_val, bool prev_b) {
  if (prev_val >= K) return 0;
  if (ind == n) return prev_b ? K - prev_val : 0;
  int& res = memo[ind][prev_val][prev_b];
  if (res != -1) return res;
  res = 0;
  if (arr[ind] != -1) {
    if (arr[ind] < prev_val && !prev_b) {
      res = 0;
    } else if (arr[ind] <= prev_val) {
      res = solve(ind + 1, arr[ind], true);
      res = (res - solve(ind + 1, arr[ind] + 1, true) + MOD) % MOD;
    } else {
      res = solve(ind + 1, arr[ind], false);
      res = (res - solve(ind + 1, arr[ind] + 1, false) + MOD) % MOD;
    }
  } else {
    if (prev_b) {
      res = (solve(ind + 1, 1, true) - solve(ind + 1, prev_val, true) + MOD) %
            MOD;
    }
    if (prev_val != 0) {
      res = (res + solve(ind + 1, prev_val, true)) % MOD;
      res = (res - solve(ind + 1, prev_val + 1, true) + MOD) % MOD;
    }
    res = (res + solve(ind + 1, prev_val + 1, false)) % MOD;
  }
  res = (res + solve(ind, prev_val + 1, prev_b)) % MOD;

  // cout << ind << " " << prev_val << " " << prev_b << " " << res << endl;
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
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cout << (solve(0, 0, false) - solve(0, 1, false) + MOD) % MOD << endl;

  return 0;
}