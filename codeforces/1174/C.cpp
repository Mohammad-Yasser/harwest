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

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int val[N];

void build() {
  int nxt_val = 1;
  for (int i = 2; i < N; ++i) {
    if (val[i] != 0) continue;
    val[i] = nxt_val++;
    if (1LL * i * i > N) continue;
    for (int j = i * i; j < N; j += i) {
      val[j] = val[i];
    }
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  build();

  int n;
  cin >> n;

  for (int i = 2; i <= n; ++i) {
    cout << val[i] << " ";
  }
}
