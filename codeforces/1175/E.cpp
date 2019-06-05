#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 5e5 + 5;
const int Lg = 20;

int l[N];
int r[N];

int mx[N];

int anc[N][Lg];

void build() {
  for (int i = 0; i < N; ++i) {
    anc[i][0] = mx[i];
    if (mx[i] <= i) {
      anc[i][0] = -1;
    }
  }

  for (int lg = 1; lg < Lg; ++lg) {
    for (int i = 0; i < N; ++i) {
      if (anc[i][lg - 1] == -1) {
        anc[i][lg] = -1;
        continue;
      }
      anc[i][lg] = anc[anc[i][lg - 1]][lg - 1];
      if (anc[i][lg] <= anc[i][lg - 1]) {
        anc[i][lg] = -1;
      }
    }
  }

}

int f(int x, int y) {
  if (x >= y) return 0;
  int res = 0;
  int curr = x;
  for (int i = Lg - 1; i >= 0 && curr < y; --i) {
    if (anc[curr][i] != -1 && anc[curr][i] <= y) {
      res += (1 << i);
      curr = anc[curr][i];
      ++i;
    }
  }
  if (mx[curr] >= y && curr < y) {
    ++res;
    curr = y;
  }
  if (curr < y) return -1;
  return res;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    ++l[i], ++r[i];
    mx[l[i]] = max(mx[l[i]], r[i]);
  }

  for (int i = 1; i < N; ++i) {
    mx[i] = max(mx[i], mx[i - 1]);
  }

  build();

  while (m--) {
    int x, y;
    cin >> x >> y;
    ++x, ++y;
    cout << f(x, y) << endl;
  }
}

