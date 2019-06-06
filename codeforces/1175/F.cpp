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

vector<int> buildNxt(const vector<int>& arr) {
  int n = arr.size();
  vector<int> nxt(n, n);
  vector<int> last(n + 1, n);
  for (int i = arr.size() - 1; i >= 0; --i) {
    nxt[i] = last[arr[i]];
    last[arr[i]] = i;
  }
  return nxt;
}

vector<int> buildOnes(const vector<int>& arr) {
  int n = arr.size();
  vector<int> ones;
  ones.push_back(-1);

  for (int i = 0; i < n; ++i) {
    if (arr[i] == 1) {
      ones.push_back(i);
    }
  }

  ones.push_back(n);
  return ones;
}

int solve(const vector<int>& arr) {
  vector<int> nxt = buildNxt(arr);
  vector<int> ones = buildOnes(arr);

  int res = 0;

  for (int i = 1; i + 1 < ones.size(); ++i) {
    vector<int> right;
    int curr_r = ones[i + 1] - 1;
    for (int j = ones[i] + 1; j <= curr_r; ++j) {
      right.push_back(arr[j]);
      curr_r = min(curr_r , nxt[j] - 1);
      if (right.size() > 1) {
        right.back() = max(right.back(), right[right.size() - 2]);
      }
    }
    int curr_left_mx = 1;
    for (int j = ones[i]; j > ones[i - 1]; --j) {
      if (nxt[j] < ones[i]) break;
      while (nxt[j] <= curr_r) {
        --curr_r;
        right.pop_back();
      }
      curr_left_mx = max(curr_left_mx, arr[j]);
      int corr_r = curr_left_mx - (ones[i] - j + 1);
      if (corr_r > right.size()) continue;
      if (corr_r == 0 || right[corr_r - 1] < curr_left_mx) {
        ++res;
      }
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


  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int res = solve(arr);
  reverse(arr.begin(), arr.end());
  res += solve(arr);
  res -= count(arr.begin(), arr.end(), 1);

  cout << res << endl;

}
