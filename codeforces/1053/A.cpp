#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
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

void answer(int x, int y) {
  cout << "YES" << endl;
  cout << x << " " << 0 << endl;
  cout << 0 << " " << 0 << endl;
  cout << 0 << " " << y << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  Long n, m, k;
  cin >> n >> m >> k;
  if (2 * n * m % k != 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (__gcd(2 * n, k) == 1) {
    answer(n, 2 * m / k);
  } else {
    answer(2 * n / __gcd(2 * n, k), m / (k / __gcd(2 * n, k)));
  }

  return 0;
}