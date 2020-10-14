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

const int N = 1e5 + 5;
int cnt_s[N];
int cnt_t[N];
int prev_b_s[N];
int prev_b_t[N];

int ls, rs, lt, rt;

bool valid() {
  --ls, --lt;
  int sb = rs - ls - (cnt_s[rs] - cnt_s[ls]);
  int tb = rt - lt - (cnt_t[rt] - cnt_t[lt]);
  int cnt_b = tb - sb;
  if (cnt_b < 0 || cnt_b % 2 == 1) return false;
  int sa = rs - max(ls, prev_b_s[rs]);
  int ta = rt - max(lt, prev_b_t[rt]);
  int last_block_a = sa - ta;
  if (last_block_a < 0) return false;
  if (last_block_a == 0) return cnt_b == 0 || sb > 0;
  return (cnt_b > 0) || (last_block_a % 3 == 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s, t;
  cin >> s >> t;
  for (int i = 1; i <= sz(s); ++i) {
    cnt_s[i] = cnt_s[i - 1] + (s[i - 1] == 'A');
    prev_b_s[i] = (s[i - 1] == 'A' ? prev_b_s[i - 1] : i);
  }
  for (int i = 1; i <= sz(t); ++i) {
    cnt_t[i] = cnt_t[i - 1] + (t[i - 1] == 'A');
    prev_b_t[i] = (t[i - 1] == 'A' ? prev_b_t[i - 1] : i);
  }
  int q;
  cin >> q;
  while (q--) {
    cin >> ls >> rs >> lt >> rt;
    cout << valid();
  }
  cout << endl;

  return 0;
}