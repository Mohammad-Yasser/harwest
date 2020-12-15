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
int n, m;

const int B = 32;
vector<int> v[B];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  cin >> n >> m;
  vector<int> a(n);
  cin >> a;
  sort(rall(a));
  while (m--) {
    int x;
    cin >> x;
    v[x].emplace_back(1);
  }

  int res = 0;
  for (int b = 0; b + 1 < B; ++b) {
    for (int x : a) {
      if (v[b].empty()) break;
      if (((x >> b) & 1)) {
        res += v[b].back();
        v[b].pop_back();
      }
    }

    for (int i = 0; i < sz(v[b]); ++i) {
      if (i == 0 && (sz(v[b]) & 1)) {
        v[b + 1].emplace_back(v[b][0]);
      } else {
        v[b + 1].emplace_back(v[b][i] + v[b][i + 1]);
        ++i;
      }
    }
  }

  cout << res << endl;

  return 0;
}