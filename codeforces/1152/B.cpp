#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

  int x;
  cin >> x;

  vector<int> ns;
  ns.emplace_back(0);

  for (int i = 0; (1 << i) <= x; ++i) {
    if (~x & (1 << i)) {
      ns.push_back(i);
    }
  }

  cout << ns.size() * 2 - 1 << endl;

  for (int x : ns) {
    cout << x << " ";
  }

}
