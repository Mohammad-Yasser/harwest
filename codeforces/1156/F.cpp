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

const int MOD = 998244353;
const int N = 5003;
int memo[N][N];
int mod_inv[N];
int freq[N];

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

void buildModInverse() {
  for (int i = 1; i < N; ++i) {
    mod_inv[i] = modInverse(i);
  }
}

int p(int x, int cnt) {
  if (x <= 1 || cnt <= 1) return 0;
  int p1 = 1LL * mod_inv[cnt] * x % MOD;
  int p2 = 1LL * mod_inv[cnt - 1] * (x - 1) % MOD;
  return 1LL * p1 * p2 % MOD;
}

int solve(int prev, int cnt) {
  if (cnt == 0) return 0;
  if (prev == N) return 0;
  int& res = memo[prev][cnt];
  if (res != -1) return res;
  // Win now
  res = p(freq[prev], cnt);

  int choose_curr = 1LL * freq[prev] * mod_inv[cnt] % MOD;
  choose_curr = 1LL * choose_curr * solve(prev + 1, cnt - 1) % MOD;

  int skip_curr = solve(prev + 1, cnt);
  res = (res + choose_curr) % MOD;
  res = (res + skip_curr) % MOD;

  // cout << prev << " " << cnt << " " << res << endl;
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
  buildModInverse();

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++freq[x];
  }

  memset(memo, -1, sizeof memo);
  cout << solve(0, n) << endl;

  return 0;
}