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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  n *= 2;
  vector<int> v(n);
  for (int& x : v) {
    cin >> x;
  }

  sort(v.begin(), v.end());

  if (v[0] == v.back()) {
    cout << -1;
    return 0;
  }

  for (int x : v) {
    cout << x << " ";
  }

}
