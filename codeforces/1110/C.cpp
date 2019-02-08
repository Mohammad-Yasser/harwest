#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/numeric>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))

typedef long long Long;

const int N = 26;
int ans[] = { 0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681,
  21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401 };

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int q;

  cin >> q;

  while (q--) {
    int a;
    cin >> a;
    int mx_pw2 = 0;
    while ((1 << (mx_pw2 + 1)) <= a) {
      ++mx_pw2;
    }

    if (a == (1 << (mx_pw2 + 1)) - 1) {
      cout << ans[mx_pw2 + 1] << endl;
    } else {
      cout << (1 << (mx_pw2 + 1)) - 1 << endl;
    }
  }

}

