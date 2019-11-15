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

const int K = 17;
unordered_map<Long, int> in_box;
Long sum[K];
vector<int> vals[K];

pair<int, int> res[K];
Long needed_sum;

bool dfs(int box, int val) {
  Long rem = needed_sum - (sum[box] - val);
  if (in_box.count(rem) == 0 || res[in_box[rem]].second != -1
    || (res[in_box[rem]].first != -1 && res[in_box[rem]].first != rem)) {
    return false;
  }

  if (res[in_box[rem]].first == rem) {
    res[in_box[rem]].second = box;
    return true;
  }

  res[in_box[rem]].first = rem;
  res[in_box[rem]].second = box;

  return dfs(in_box[rem], rem);
}
int parent[1 << K];

pair<int, int> mask_res[1 << K][K];
int k;

void doZeroes() {
  int mask = 0;
  for (int i = 0; i < k; ++i) {
    if (sum[i] == needed_sum) {
      res[i].first = vals[i][0], res[i].second = i;
      mask |= (1 << i);
    }
  }
  parent[mask] = mask;
  for (int i = 0; i < k; ++i) {
    if (sum[i] == needed_sum) {
      mask_res[mask][i] = res[i];
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> k;

  for (int i = 0; i < k; ++i) {
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      sum[i] += x;
      needed_sum += x;
      in_box[x] = i;
      vals[i].push_back(x);
    }
  }
  if (needed_sum % k != 0) {
    cout << "No" << endl;
    return 0;
  }
  needed_sum /= k;

  memset(parent, -1, sizeof parent);
  doZeroes();

  for (int i = 0; i < k; ++i) {
    for (int x : vals[i]) {
      memset(res, -1, sizeof res);
      res[i].first = x;
      bool valid = true;
      if (dfs(i, x)) {
        int mask = 0;
        for (int j = 0; j < k; ++j) {
          if (res[j].second != -1) {
            mask |= (1 << j);
          }
        }
        parent[mask] = mask;
        for (int j = 0; j < k; ++j) {
          if (res[j].second != -1) {
            mask_res[mask][j] = res[j];
          }
        }
      }
    }
  }

  for (int mask = 0; mask < (1 << k); ++mask) {
    if (parent[mask] == mask) continue;
    for (int submask = 0; submask = submask - mask & mask;) {
      if (parent[submask] == submask && parent[mask ^ submask] != -1) {
        parent[mask] = submask;
        break;
      }
    }
  }

  if (parent[(1 << k) - 1] == -1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  int curr_mask = (1 << k) - 1;

  while (curr_mask != 0) {
    int parent_mask = parent[curr_mask];
    for (int j = 0; j < k; ++j) {
      if (((parent_mask >> j) & 1) == 1) {
        res[j] = mask_res[parent_mask][j];
      }
    }
    curr_mask ^= parent_mask;
  }

  for (int i = 0; i < k; ++i) {
    cout << res[i].first << " " << res[i].second + 1 << endl;
  }

}
