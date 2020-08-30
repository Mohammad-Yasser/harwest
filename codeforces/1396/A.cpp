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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  vector<Long> a(n);
  cin >> a;

  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << -a[0] << endl;

    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;

    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    return 0;
  }

  cout << 1 << " " << n - 1 << endl;
  for (int i = 0; i + 1 < n; ++i) {
    Long x = 1LL * (a[i] % n) * (n - 1);
    cout << x << " ";
    a[i] += x;
  }
  cout << endl;

  cout << n << " " << n << endl;
  cout << -a.back() << endl;
  a.back() = 0;

  cout << 1 << " " << n << endl;
  for (int i = 0; i < n; ++i) {
    cout << -a[i] << " ";
  }
  cout << endl;

  return 0;
}