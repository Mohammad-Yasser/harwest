#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef vector<int> vi;

const int N = 6;

int arr[N];

int x_boundary[N][2];
int y_boundary[N][2];
int z_boundary[N][2];

bool inRange(int l, int r, int x) { return x > l && x < r; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int x, y, z;
  cin >> x >> y >> z;

  int cx, cy, cz;
  cin >> cx >> cy >> cz;

  for (int i = 0; i < N; ++i) {
    x_boundary[i][0] = y_boundary[i][0] = z_boundary[i][0] = INT_MIN;
    x_boundary[i][1] = y_boundary[i][1] = z_boundary[i][1] = INT_MAX;
  }

  y_boundary[0][1] = 0;
  y_boundary[1][0] = cy;

  z_boundary[2][1] = 0;
  z_boundary[3][0] = cz;

  x_boundary[4][1] = 0;
  x_boundary[5][0] = cx;

  int res = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (inRange(x_boundary[i][0], x_boundary[i][1], x) &&
        inRange(y_boundary[i][0], y_boundary[i][1], y) &&
        inRange(z_boundary[i][0], z_boundary[i][1], z)) {
      res += a;
    }
  }

  cout << res << endl;

  return 0;
}
