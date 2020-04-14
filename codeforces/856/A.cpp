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
typedef vector<int> vi;

const int N = 1e6 + 5;

bool vis[N];

bool valid(const vector<int>& b) {
  for (int x : b) {
    if (vis[b.back() - x]) return false;
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
    memset(vis, 0, sizeof vis);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
      cin >> x;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        vis[arr[j] - arr[i]] = true;
      }
    }
    vector<int> b;
    b.emplace_back(1);
    while (b.size() != n) {
      b.emplace_back(b.back() + 1);
      while (!valid(b) && b.back() < 1e6 + 10) {
        ++b.back();
      }
    }
    if (b.back() > 1e6 + 3) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int x : b) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}