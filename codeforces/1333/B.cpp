#ifndef Local
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
// gp_hash_table<int, int> table;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long Long;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    multiset<int> st;
    for (int& x : a) {
      cin >> x;
      st.insert(x);
    }
    for (int& x : b) {
      cin >> x;
    }
    bool valid = true;
    for (int i = n - 1; i >= 0; --i) {
      st.erase(st.find(a[i]));
      if (a[i] == b[i]) continue;
      if (st.count((a[i] < b[i]) ? 1 : -1) == 0) {
        valid = false;
        break;
      }
    }
    cout << (valid ? "YES" : "NO") << endl;
  }

  return 0;
}
