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
typedef long long Long;
typedef double Double;

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

const int N = 1e7 + 5;

int cnt[N][2];

int smallest_prime[N];

void build() {
  for (int i = 2; i < N; ++i) {
    if (smallest_prime[i]) continue;
    smallest_prime[i] = i;
    if (i > N / i) continue;
    for (int j = i * i; j < N; j += i) {
      smallest_prime[j] = i;
    }
  }
}

void add(int x, bool c) {
  if (x == 1) return;
  ++cnt[smallest_prime[x]][c];
  add(x / smallest_prime[x], c);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  build();

  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int& x : a) {
    cin >> x;
    add(x, 0);
  }

  for (int& x : b) {
    cin >> x;
    add(x, 1);
  }

  cout << n << " " << m << endl;
  for (int x : a) {
    int res = 1;
    while (x != 1) {
      if (cnt[smallest_prime[x]][1] == 0) {
        res *= smallest_prime[x];
      } else {
        --cnt[smallest_prime[x]][1];
      }
      x /= smallest_prime[x];
    }
    cout << res << " ";
  }
  cout << endl;
  for (int x : b) {
    int res = 1;
    while (x != 1) {
      if (cnt[smallest_prime[x]][0] == 0) {
        res *= smallest_prime[x];
      } else {
        --cnt[smallest_prime[x]][0];
      }
      x /= smallest_prime[x];
    }
    cout << res << " ";
  }
  cout << endl;
  return 0;
}