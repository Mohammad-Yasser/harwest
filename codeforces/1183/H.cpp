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

const Long OO = LLONG_MAX / 2;
const int N = 101;
const int A = 'z' - 'a' + 1;
Long memo[N][N];
string s;
int n;
int nxt[N][A];
Long count(int ind, int length) {
  if (length <= 0) return 0;
  if (ind == n) return 0;
  if (length == 1) return 1;

  auto& res = memo[ind][length];
  if (res != -1) return res;
  res = 0;
  for (int c = 0; c < A; ++c) {
    res += count(nxt[ind][c], length - 1);
    res = min(res, OO);
  }
  return res;
}

void build() {
  for (int i = n - 1; i >= 0; --i) {
    for (int c = 0; c < A; ++c) {
      if (i == n - 1) {
        nxt[i][c] = n;
      } else {
        if (s[i + 1] == c + 'a') {
          nxt[i][c] = i + 1;
        } else {
          nxt[i][c] = nxt[i + 1][c];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long k;
  cin >> n >> k;
  cin >> s;
  s = "a" + s;
  ++n;
  build();
  memset(memo, -1, sizeof memo);
  Long res = 0;
  for (int i = n; i >= 1; --i) {
    Long cnt = count(0, i);
    cnt = min(cnt, k);
    res += (n - i) * cnt;
    k -= cnt;
  }
  if (k != 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << res << endl;

  return 0;
}