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

const int A = 'z' - 'a' + 1;
vector<int> occ[A];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;
  for (int i = 0; i < sz(s); ++i) {
    string t = s;
    rotate(begin(t), begin(t) + i, end(t));
  }
  int cnt_valid = 0;
  for (int i = 0; i < sz(s); ++i) {
    occ[s[i] - 'a'].emplace_back(i);
  }
  bitset<A> bs;
  vector<int> cnt(A, 0);
  for (auto& v : occ) {
    int mx = 0;
    for (int i = 0; i < sz(s); ++i) {
      fill(all(cnt), 0);
      for (int j : v) {
        auto c = s[(i + j) % sz(s)] - 'a';
        ++cnt[c];
      }
      mx = max(mx, int(count(all(cnt), 1)));
    }
    cnt_valid += mx;
  }

  cout << fixed << setprecision(10) << 1.0 * cnt_valid / sz(s) << endl;

  return 0;
}