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

bool isPrime(int n) {
  for (int i = 2; i <= n / i; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

bool solve(int n) {
  if (n == 1) return false;
  if (n % 2 == 1) return true;
  if (n == 2) return true;
  int x = 1;
  while (n % 2 == 0) {
    x *= 2;
    n /= 2;
  }
  if (n == 1) return false;
  if (x != 2) return true;
  return !isPrime(n);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    cout << (solve(n) ? "Ashishgup" : "FastestFinger") << endl;
  }
  return 0;
}