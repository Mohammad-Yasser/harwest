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
string s;
int n, k;

bool check() {
  for (int i = 0; i < k; ++i) {
    for (int t = 0; t < 2; ++t) {
      for (int j = i + k; j < n; j += k) {
        if (s[i] == '?' && s[j] == '?') continue;
        if (s[i] == '?') {
          s[i] = s[j];
        } else if (s[j] == '?') {
          s[j] = s[i];
        } else if (s[i] != s[j]) {
          return false;
        }
      }
    }
  }
  s = s.substr(0, k);
  int ones = count(all(s), '1');
  int q = count(all(s), '?');
  int zeroes = k - ones - q;
  while (ones != zeroes) {
    if (q == 0) return false;
    if (ones < zeroes) {
      ++ones;
    } else {
      ++zeroes;
    }
    --q;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    cout << (check() ? "YES" : "NO") << endl;
  }
  return 0;
}