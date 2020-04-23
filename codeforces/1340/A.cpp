#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)

typedef long long Long;

bool valid(int n, const vector<int>& arr, const vector<int>& pos) {
  int curr_elem = 0;
  int curr_pos = pos[0];
  int r = n;

  while (curr_elem != n) {
    curr_pos = pos[curr_elem];
    int nxt_r = curr_pos;
    while (curr_pos != r) {
      if (arr[curr_pos] != curr_elem) return false;
      ++curr_pos;
      ++curr_elem;
    }
    r = nxt_r;
  }
  return true;
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
    int n;
    cin >> n;
    vector<int> arr(n), pos(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      --arr[i];
      pos[arr[i]] = i;
    }
    cout << (valid(n, arr, pos) ? "Yes" : "No") << endl;
  }

  return 0;
}
