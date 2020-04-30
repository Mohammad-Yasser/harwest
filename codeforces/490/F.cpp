#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
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

typedef long long Long;
typedef long double Double;
typedef vector<int> vi;

const int N = 6003;

int r[N];

vector<int> adj[N];

struct SegmentTree {
  vector<int> tree;
  SegmentTree() : tree(3 * N, 0) {}
  void modify(int p, int value) {  // set value at position p
    for (tree[p += N] = value; p > 1; p >>= 1)
      tree[p >> 1] = max(tree[p], tree[p ^ 1]);
  }
  // r exclusive
  int query(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max(res, tree[l++]);
      if (r & 1) res = max(res, tree[--r]);
    }
    return res;
  }
} seg_tree;

int res = 0;
void dfs(int node, int parent) {
  int prev = seg_tree.query(r[node], r[node]);
  int q = seg_tree.query(1, r[node]);
  seg_tree.modify(r[node], q + 1);
  res = max(res, q + 1);
  for (int v : adj[node]) {
    if (v == parent) continue;
    dfs(v, node);
  }
  seg_tree.modify(r[node], prev);
}

int n;

void compress() {
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.emplace_back(r[i]);
  }
  v.emplace_back(0);
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; ++i) {
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> r[i];
  }
  compress();

  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].emplace_back(y), adj[y].emplace_back(x);
  }

  int res = 0;

  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() != 1) continue;
    dfs(i, -1);
    res = max(res, ::res);
  }

  cout << res << endl;

  return 0;
}
