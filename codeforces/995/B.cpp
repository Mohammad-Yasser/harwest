#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

// gp_hash_table<int, int> table;
const int N = 201;
int arr[N];
int n;
int solve() {
  int res = 0;

  for (int i = 0 ; i < n ; i += 2) {
    int j = i + 1;
    while (arr[j] != arr[i]) {
      ++j;
    }
    while (j != i + 1) {
      swap(arr[j] , arr[j - 1]);
      ++res;
      --j;
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  n *=  2;

  for (int i = 0 ; i < n ; ++i) {
    cin >> arr[i];
  }

  cout << solve() << endl;
}
