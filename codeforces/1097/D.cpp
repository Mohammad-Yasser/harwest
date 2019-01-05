#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 1e4 + 5;
const int Lg = 70;
const int MOD = round(1e9 + 7);

Long power(Long b, Long p) {
  if (p == 0) return 1;
  Long tmp = power(b, p / 2);
  tmp = tmp * tmp % MOD;
  if (p & 1LL) {
    tmp = tmp * b % MOD;
  }
  return tmp;
}

Long modInv(Long x) {
  return power(x, MOD - 2);
}

Long ex[N][Lg];

Long E(Long n, int k, Long p, int pw = 0) {
  if (ex[k][pw] != -1) return ex[k][pw];
  if (k == 0) return n;

  Long res = 0;
  int cnt = 0;

  for (Long tmp_n = n; tmp_n != 0; tmp_n /= p, ++cnt) {
    res = (res + E(tmp_n, k - 1, p, pw + cnt)) % MOD;
  }

  res = res * modInv(cnt) % MOD;
  return ex[k][pw] = res;
}

vector<pair<Long, Long>> factorize(Long n) {
  vector<pair<Long, Long>> res;
  for (Long i = 2; i * i <= n; ++i) {
    Long curr = 1;
    while (n % i == 0) {
      curr *= i;
      n /= i;
    }
    if (curr != 1) res.emplace_back(curr, i);
  }
  if (n != 1) res.emplace_back(n, n);
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long n;
  int k;
  cin >> n >> k;

  auto prime_powers = factorize(n);

  Long res = 1;

  for (auto x : prime_powers) {
    memset(ex, -1, sizeof ex);
    res = res * E(x.first, k, x.second) % MOD;
  }

  cout << res;

}
