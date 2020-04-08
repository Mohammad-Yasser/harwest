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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long Long;
typedef vector<int> vi;

string s;

void performTurn(int i) { swap(s[i], s[i + 1]); }

bool checkTurn(int i) {
  return i + 1 < s.size() && s[i] == 'R' && s[i + 1] == 'L';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  cin >> s;
  int cnt_inversions = 0;
  int cnt_R = 0;
  vector<int> turns;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      cnt_inversions += cnt_R;
    } else {
      ++cnt_R;
    }
    if (i + 1 < n && s[i] == 'R' && s[i + 1] == 'L') {
      turns.emplace_back(i);
    }
  }
  if (cnt_inversions < k) {
    cout << -1 << endl;
    return 0;
  }
  vector<vector<int>> res;
  while (k--) {
    res.emplace_back(vector<int>());
    vector<int> nxt_turns;
    while (!turns.empty() && cnt_inversions > k) {
      int x = turns.back();
      turns.pop_back();
      res.back().emplace_back(x);
      performTurn(x);
      if (checkTurn(x - 1)) {
        nxt_turns.emplace_back(x - 1);
      }
      if (checkTurn(x + 1)) {
        nxt_turns.emplace_back(x + 1);
      }
      --cnt_inversions;
    }
    turns.insert(turns.end(), all(nxt_turns));
  }
  if (cnt_inversions != 0) {
    cout << -1 << endl;
    return 0;
  }
  for (auto& v : res) {
    cout << v.size() << " ";
    for (int x : v) {
      cout << x + 1 << " ";
    }
    cout << endl;
  }
}
