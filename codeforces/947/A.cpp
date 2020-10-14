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

template <class T>
vector<pair<T, int>> getPrimeFactorization(T n) {
  vector<pair<T, int>> res;
  for (int i = 2; 1LL * i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.emplace_back(i, 0);
    while (n % i == 0) {
      ++res.back().second;
      n /= i;
    }
  }
  if (n != 1) {
    res.emplace_back(n, 1);
  }
  return res;
}

const int N = 1e6 + 5;
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  auto prime_factors = getPrimeFactorization(n);
  for (auto& [p, c] : prime_factors) {
    int x1_low = n - p + 1;
    int x1_high = n - 1;
    ++cnt[x1_low];
    --cnt[x1_high + 1];
  }
  ++cnt[n], --cnt[n + 1];

  int res = n;
  for (int i = 1; i < N; ++i) {
    cnt[i] += cnt[i - 1];
    if (cnt[i] > 0) {
      auto prime_factors = getPrimeFactorization(i);
      if (sz(prime_factors) == 1 && prime_factors[0].second == 1)
        continue;  // Cannot be a prime number.

      for (auto& [p, c] : prime_factors) {
        res = min(res, i - p + 1);
      }
    }
  }
  cout << res << endl;

  return 0;
}