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

string vowels = "aeiou";

void solve(int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << vowels[j % vowels.size()];
    }
    rotate(begin(vowels), begin(vowels) + 1, end(vowels));
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int k;
  cin >> k;

  for (int i = vowels.size(); i * i <= k; ++i) {
    if (k % i == 0 && k / i >= vowels.size()) {
      solve(i, k / i);
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}