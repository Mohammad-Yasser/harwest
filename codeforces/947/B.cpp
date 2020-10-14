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
  vector<int> v(n), t(n);
  cin >> v >> t;
  multiset<Long> ms;
  Long shift = 0;

  for (int i = 0; i < n; ++i) {
    ms.emplace(v[i] + shift);
    Long res = 0;
    while (!ms.empty() && *ms.begin() <= shift + t[i]) {
      res += *ms.begin() - shift;
      ms.erase(ms.begin());
    }
    res += 1LL * t[i] * sz(ms);
    cout << res << " ";
    shift += t[i];
  }
  cout << endl;
  return 0;
}