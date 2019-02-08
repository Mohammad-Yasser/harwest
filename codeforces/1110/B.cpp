#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/numeric>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))

typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m, k;
  cin >> n >> m >> k;

  Long res = n;

  vector<int> diff;

  int last = 0;
  cin >> last;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    diff.push_back(x - last - 1);
    last = x;
  }

  sort(diff.begin(), diff.end());

  for (int i = 0; i < n - k; ++i) {
    res += diff[i];
  }

  cout << res;
}

