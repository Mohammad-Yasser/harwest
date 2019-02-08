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

  int parity = 0;
  int b, k;
  cin >> b >> k;

  b &= 1;

  vector<int> a(k);
  for (int& x : a) {
    cin >> x;
    x &= 1;
  }

  reverse(a.begin(), a.end());
  int curr = 1;

  for (int x : a) {
    parity += x * curr;
    curr *= b;
    parity &= 1;
    curr &= 1;
  }

  cout << (parity ? "odd" : "even");

}

