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

vector<bool> v;

int solve() {
  int cnt[2] = {0, 0};
  for (bool x : v) {
    if (cnt[x] == 0) {
      ++cnt[!x];
    } else {
      --cnt[x];
      ++cnt[!x];
    }
  }
  return cnt[0] + cnt[1];
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

  string a, b;
  cin >> a >> b;
  if (count(all(a), '1') != count(all(b), '1')) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) v.emplace_back(a[i] == '1');
  }
  cout << solve() << endl;
  return 0;
}