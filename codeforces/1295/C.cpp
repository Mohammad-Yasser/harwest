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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int A = 30;
vector<int> pos[A];

void init() {
  for (auto& p : pos) {
    p.clear();
  }
}

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
    init();

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); ++i) {
      pos[s[i] - 'a'].emplace_back(i);
    }

    int res = 1;
    int ind_s = 0;
    bool valid = true;

    for (char c : t) {
      c -= 'a';
      if (pos[c].empty()) {
        valid = false;
        break;
      }
      auto nxt = lower_bound(pos[c].begin(), pos[c].end(), ind_s);
      if (nxt == pos[c].end()) {
        ++res;
        ind_s = 0;
        nxt = lower_bound(pos[c].begin(), pos[c].end(), ind_s);
      }
      ind_s = *nxt + 1;
    }

    cout << (valid ? res : -1) << endl;

  }

}
