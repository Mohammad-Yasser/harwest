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

// gp_hash_table<int, int> table;
const int N = 1e6 + 3;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> events(n);

  vector<bool> in(N);
  vector<int> last_day(N);

  vector<int> days;
  int cnt = 0;
  while (n--) {
    if (cnt == 0) {
      days.push_back(0);
    }
    ++days.back();
    int x;
    cin >> x;
    bool enter = (x > 0);
    x = abs(x);
    if (!enter) {
      if (!in[x]) {
        cout << -1 << endl;
        return 0;
      }
      in[x] = false;
      --cnt;
    } else {
      if (in[x] || last_day[x] == days.size()) {
        cout << -1 << endl;
        return 0;
      }
      in[x] = true;
      last_day[x] = days.size();
      ++cnt;
    }
  }

  if (cnt != 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << days.size() << endl;
  for (int x : days) {
    cout << x << " ";
  }

}
