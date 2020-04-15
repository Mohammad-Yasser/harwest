#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

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
typedef vector<int> vi;

bool valid(int mx, const vector<int>& v, int m) {
  int prev = 0;
  for (int x : v) {
    if (x < prev && prev - x > mx) return false;
    if (x > prev && m - x + prev > mx) {
      prev = x;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  vector<int> v(n);

  for (int& x : v) {
    cin >> x;
  }

  int low = 0, high = 1e7, ans;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (valid(mid, v, m)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}