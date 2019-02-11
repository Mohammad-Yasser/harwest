#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& x : a) {
    cin >> x;
  }
  for (int& x : b) {
    cin >> x;
  }
  multiset<int> da, db;
  for (int i = 1; i < n; ++i) {
    da.insert(a[i] - a[i - 1]);
    db.insert(b[i] - b[i - 1]);
  }
  cout << ((a[0] == b[0] && da == db) ? "YES" : "NO");
}
