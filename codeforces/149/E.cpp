#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

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

using vi = vector<int>;

vi Z(const string& S) {
  vi z(sz(S));
  int l = -1, r = -1;
  rep(i, 1, sz(S)) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}

vi buildMaxPrefix(const string& p, const string& s) {
  string concat = p + "$" + s;
  vi z = Z(concat);
  z.erase(begin(z), begin(z) + sz(p) + 1);
  vi res(sz(s), 0);
  for (int i = 0; i < sz(z); ++i) {
    if (z[i] != 0) res[i + z[i] - 1] = max(res[i + z[i] - 1], z[i]);
  }
  for (int i = 1; i < sz(s); ++i) {
    res[i] = max(res[i], res[i - 1]);
  }
  for (int i = sz(s) - 2; i >= 0; --i) {
    res[i] = max(res[i], res[i + 1] - 1);
  }
  return res;
}

template <class T>
T reversed(const T& s) {
  T res = s;
  reverse(all(res));
  return res;
}

bool check(const string& p, const string& s) {
  if (sz(p) == 1) return false;
  vi max_prefix = buildMaxPrefix(p, s);
  string rev_s = reversed(s), rev_p = reversed(p);
  vi max_suffix = reversed(buildMaxPrefix(rev_p, rev_s));

  for (int i = 0; i + 1 < sz(s); ++i) {
    if (max_prefix[i] + max_suffix[i + 1] >= sz(p)) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  cin >> s;
  int m;
  cin >> m;
  int res = 0;
  while (m--) {
    string p;
    cin >> p;
    res += check(p, s);
  }

  cout << res << endl;

  return 0;
}