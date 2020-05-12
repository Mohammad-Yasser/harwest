#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef double Double;

const int N = 2e5 + 5;

vector<int> powers[N];
vector<pair<int, int>> prime_factors[N];

vector<pair<int, int>> buildPrimeFactors(int d) {
  vector<pair<int, int>> res;
  for (int i = 2; i * i <= d; ++i) {
    if (d % i != 0) continue;
    res.emplace_back(i, 0);
    while (d % i == 0) {
      d /= i;
      ++res.back().second;
    }
  }
  if (d != 1) {
    res.emplace_back(d, 1);
  }
  return res;
}

void init() {
  for (int i = 2; i < N; ++i) {
    prime_factors[i] = buildPrimeFactors(i);
  }
}

int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res;
  if (p & 1) {
    res = 1LL * res * base;
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

  init();

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (auto& p : prime_factors[x]) {
      powers[p.first].emplace_back(p.second);
    }
  }

  Long res = 1;
  for (int i = 2; i < N; ++i) {
    if (powers[i].size() < n - 1) continue;
    while (powers[i].size() < n) {
      powers[i].emplace_back(0);
    }
    sort(all(powers[i]));
    res *= power(i, powers[i][1]);
  }

  cout << res << endl;

  return 0;
}