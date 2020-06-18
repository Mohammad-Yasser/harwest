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
typedef unsigned long long Long;
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

int f(int a, int b, int n) {
  if (max(a, b) > n) return 0;
  return 1 + f(b, a + b, n);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long k;
  cin >> k;
  vector<int> cnt(10, 1);
  Long curr = 1;
  for (int i = 0; curr < k; i = (i + 1) % 10) {
    curr = curr / cnt[i];
    ++cnt[i];
    curr = curr * cnt[i];
  }
  string s = "codeforces";
  for (int i = 0; i < 10; ++i) {
    int x = cnt[i];
    while (x--) {
      cout << s[i];
    }
  }
  cout << endl;
  return 0;
}