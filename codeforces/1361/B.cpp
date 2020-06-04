#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

typedef long long Long;
typedef long double Double;
typedef vector<int> vi;

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

const int MOD = 1000000007;

int power(int base, int p) {
  if (p == 0) return 1;
  int res = power(base, p / 2);
  res = 1LL * res * res % MOD;
  if (p & 1) {
    res = 1LL * res * base % MOD;
  }
  return res;
}

vector<pair<int, int>> curr;
int p;
void add(int x) {
  if (curr.empty() || curr.back().first != x) {
    curr.emplace_back(x, 1);
    return;
  }
  ++curr.back().second;
  if (!curr.empty() && curr.back().second == p) {
    curr.pop_back();
    add(x + 1);
  }
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
  vector<int> k;
  while (t--) {
    curr.clear();
    int n;
    cin >> n >> p;
    k.resize(n);
    for (int& x : k) {
      cin >> x;
    }
    if (p == 1) {
      cout << n % 2 << endl;
      continue;
    }
    sort(rbegin(k), rend(k));
    int res = 0;
    int last = -1;
    for (int x : k) {
      if (last == -1) {
        last = x;
        res = (res + power(p, x)) % MOD;
      } else {
        add(x);
        if (curr.back().first == last) {
          res = 0;
          curr.clear();
          last = -1;
        }
      }
    }
    for (auto& c : curr) {
      res = (res - (1LL * power(p, c.first) * c.second % MOD) + MOD) % MOD;
    }
    cout << res << endl;
  }

  return 0;
}