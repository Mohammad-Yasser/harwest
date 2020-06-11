#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
typedef long long Long;
typedef long double Double;

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

const int N = 1e7 + 5;
int smallest_prime[N];

void buildSmallestPrime() {
  for (int i = 2; i < N; ++i) {
    if (smallest_prime[i] != 0) {
      continue;
    }
    smallest_prime[i] = i;
    if (i > N / i) continue;
    for (int j = i * i; j < N; j += i) {
      if (smallest_prime[j] == 0) smallest_prime[j] = i;
    }
  }
}

vector<int> getPrimeFactors(int x) {
  vector<int> res;
  while (x != 1) {
    res.emplace_back(smallest_prime[x]);
    while (x % res.back() == 0) x /= res.back();
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

  buildSmallestPrime();

  int n;
  cin >> n;
  vector<vector<int>> res(2, vector<int>(n, 1));
  vector<int> prime_factors;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    prime_factors = getPrimeFactors(a);
    if (prime_factors.size() == 1) {
      res[0][i] = res[1][i] = -1;
      continue;
    }
    for (int x : prime_factors) {
      res[0][i] *= x;
    }
    res[0][i] /= prime_factors.back();
    res[1][i] = prime_factors.back();
  }

  cout << res[0] << endl;
  cout << res[1] << endl;

  return 0;
}