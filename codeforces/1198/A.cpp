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

const int N = 5e5 + 5;
int arr[N];
map<int, int> cnt;
int n, I;

void build() {
  int id = 1;
  int curr = 0;
  for (auto& p : cnt) {
    curr += p.second;
    arr[id] = curr;
    ++id;
  }
  while (id != N) {
    arr[id] = curr;
    ++id;
  }
}

bool valid(int l, int r) {
  int K = r - l + 1;
  return I > 25 || K <= (1 << I);
}

int bs(int l) {
  int low = l, high = N - 1, ans = N;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (valid(l, mid)) {
      ans = arr[N - 1] - arr[mid] + arr[l - 1];
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n >> I;
  I *= 8;
  I /= n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  build();
  int res = N;
  for (int l = 0; l < N; ++l) {
    res = min(res, bs(l));
  }

  cout << res << endl;

}
