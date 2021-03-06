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

int sum(Long a, Long n) {
  a%=MOD, n%=MOD;
  int res = (2 * a + 1LL * (n - 1) * 2) % MOD;
  res = 1LL * res * n % MOD;
  res = 1LL * res * modInverse(2) % MOD;
  return res;
}

int solve(Long n) {
  Long curr_size = 1;
  bool odd = true;
  Long nxt_odd = 1, nxt_even = 2;
  int res = 0;
  while (n > 0) {
    if (n <= curr_size) curr_size = n;
    Long a = (odd ? nxt_odd : nxt_even);
    res = (res + sum(a, curr_size)) % MOD;
    n -= curr_size;
    if (odd)
      nxt_odd += 2 * curr_size;
    else
      nxt_even += 2 * curr_size;
    curr_size *= 2;
    odd ^= 1;
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

  Long l, r;
  cin >> l >> r;
  cout << (solve(r) - solve(l - 1) + MOD) % MOD << endl;
  return 0;
}