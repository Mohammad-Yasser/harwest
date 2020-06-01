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
typedef long double Double;

const int N = 1e6 + 5;

Long cnt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int a, b, c, d;

  cin >> a >> b >> c >> d;
  for (int i = a; i <= b; ++i) {
    ++cnt[i + b];
    --cnt[i + c + 1];
  }

  for (int i = 1; i < N; ++i) {
    cnt[i] += cnt[i - 1];
  }

  for (int i = 1; i < N; ++i) {
    cnt[i] += cnt[i - 1];
  }

  Long res = 0;
  for (int i = c; i <= d; ++i) {
    res += cnt[N - 1] - cnt[i];
  }

  cout << res << endl;

  return 0;
}