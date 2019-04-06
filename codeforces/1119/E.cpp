#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 3e5 + 5;

int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  Long res = 0;
  Long prev = 0;

  for (int i = 0; i < n; ++i) {
    Long x;
    cin >> x;
    Long used_with_prev = min(prev, 1LL * x / 2);
    res += used_with_prev;
    prev -= used_with_prev;
    x -= used_with_prev * 2;
    Long equil = x / 3;
    res += equil;
    x -= equil * 3;
    prev += x;
  }

  cout << res;

}

