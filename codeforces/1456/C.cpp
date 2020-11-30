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

const int N = 1e5 + 5;

int arr[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  cin >> c;
  sort(all(c));
  Long boss = 0;
  Long score = 0;
  while (!c.empty() && boss + c.back() >= 0) {
    score += boss;
    boss += c.back();
    c.pop_back();
  }
  if (c.empty()) {
    cout << score << endl;
    return 0;
  }

  ++k;
  score += boss * ((sz(c) + k - 1) / k);
  for (int i = 0; i < sz(c); ++i) {
    Long coeff = i / k;
    score += coeff * c[i];
  }
  cout << score << endl;
  return 0;
}