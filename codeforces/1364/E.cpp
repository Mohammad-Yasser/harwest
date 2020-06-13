#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, a, b) for (int i = a; i < int(b); ++i)

typedef long long Long;
typedef double Double;
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

const int N = 3000;
int memo[N][N];

int ask(int i, int j) {
  if (i > j) swap(i, j);
  int& res = memo[i][j];
  if (res != -1) return res;
  cout << "? " << i << " " << j << endl;
  cin >> res;
  return res;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
  auto res = rng();
  res %= (r - l + 1);
  return res + l;
}

int main() {
  memset(memo, -1, sizeof memo);
  int n;
  cin >> n;

  int x, y;
  while (true) {
    x = rnd(1, n);
    y = rnd(1, n);
    if (x == y) continue;
    if (ask(x, y) & 1) continue;
    break;
  }

  vi perm(n);
  for (int i = 0; i < n; ++i) {
    perm[i] = i + 1;
  }
  shuffle(all(perm), rng);
  vi curr;
  for (int i = 0; i < n; ++i) {
    curr.emplace_back(perm[i]);
    if (curr.size() == 3) {
      int a = ask(curr[0], curr[1]);
      int b = ask(curr[2], curr[1]);
      if (a < b) {
        curr.erase(begin(curr) + 2);
      }
      if (a == b) {
        curr.erase(begin(curr) + 1);
      }
      if (a > b) {
        curr.erase(begin(curr) + 0);
      }
    }
  }
  int zero = curr[0];
  for (int i = 0; i < n; ++i) {
    if (perm[i] == curr[0] || perm[i] == curr[1]) continue;
    int a = ask(perm[i], curr[0]);
    int b = ask(perm[i], curr[1]);
    if (a < b) {
      zero = curr[0];
      break;
    }
    if (a > b) {
      zero = curr[1];
      break;
    }
  }
  vi res;
  for (int i = 1; i <= n; ++i) {
    if (i == zero) {
      res.emplace_back(0);
    } else {
      res.emplace_back(ask(zero, i));
    }
  }
  cout << "! " << res << endl;

  return 0;
}