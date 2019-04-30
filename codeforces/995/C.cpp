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

const int N = 1e5 + 5;
const int MX = round(1.5e6);

int x[N], y[N];
int n;

Long sq(Long x) {
  return x * x;
}

bool can(const vector<int>& perm, vector<int>& coeff) {
  Long dx = 0, dy = 0;
  for (int i = 0; i < n; ++i) {
    int curr = perm[i];

    if (sq(dx + x[curr]) + sq(dy + y[curr])
      < sq(dx - x[curr]) + sq(dy - y[curr])) {
      coeff[curr] = 1;
      dx += x[curr] , dy += y[curr];
    } else {
      coeff[curr] = -1;
      dx -= x[curr] , dy -= y[curr];
    }
  }
  return dx * dx + dy * dy <= 1LL * MX * MX;
}

vector<int> solve() {
  vector<int> perm(n), coeff(n);
  for (int i = 0; i < n; ++i) {
    perm[i] = i;
  }
  do {
    random_shuffle(perm.begin(), perm.end());
  } while (!can(perm, coeff));
  return coeff;
}

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  auto res = solve();
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;

}
