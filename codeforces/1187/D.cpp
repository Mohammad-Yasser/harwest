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
 
const int N = 3e5 + 5;
const int OO = 3 * N;
 
vector<int> occ[N];
 
struct Node {
  int start, end; // The node covers the range [start,end].
 
  int mn = 0;
 
  static Node merge(const Node& a, const Node& b) {
    Node res;
    res.start = a.start;
    res.end = b.end;
 
    res.mn = min(a.mn, b.mn);
 
    return res;
  }
 
  bool inRange(int x) const {
    return start <= x && x <= end;
  }
 
  void print() const {
 
  }
};
 
struct SegmentTree {
  static const int kSize = 1 << int(log2(N) + 2);
 
  array<Node, kSize> nodes;
 
  void build(int node_id, int left, int right) {
    Node& node = nodes[node_id];
    node.start = left, node.end = right;
    if (left == right) {
      node.mn = occ[node.start].back();
      return;
    }
 
    int mid = (left + right) / 2;
    build(node_id * 2, left, mid);
    build(node_id * 2 + 1, mid + 1, right);
    node = Node::merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }
 
  void build(int n) {
    build(1, 0, n + 1);
  }
 
  void update(int node_id, int ind) {
    auto& node = nodes[node_id];
    if (!node.inRange(ind)) return;
    if (node.start == node.end) {
      node.mn = occ[node.start].back();
      return;
    }
    update(node_id * 2, ind);
    update(node_id * 2 + 1, ind);
    node = Node::merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }
 
  int query(int node_id, int l, int r) {
    auto& node = nodes[node_id];
    if (l <= node.start && node.end <= r) {
      return node.mn;
    }
    if (node.end < l || node.start > r) {
      return OO;
    }
 
    int res = query(node_id * 2, l, r);
    res = min(res, query(node_id * 2 + 1, l, r));
 
    return res;
  }
 
  int query(int l, int r) {
    int res = query(1, l, r);
    return res;
  }
} segTree;
 
int a[N];
int b[N];
int n;
 
void build() {
  for (int i = 0; i <= n + 1; ++i) {
    occ[i].clear();
    occ[i].push_back(OO);
  }
  for (int i = n - 1; i >= 0; --i) {
    occ[a[i]].push_back(i);
  }
  segTree.build(n);
}
 
bool solve() {
  build();
 
  for (int i = 0; i < n; ++i) {
    if (segTree.query(0, b[i] - 1) < occ[b[i]].back()) return false;
    if (occ[b[i]].back() == OO) return false;
    occ[b[i]].pop_back();
    segTree.update(1, b[i]);
  }
 
  return true;
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif
 
  int t;
  cin >> t;
 
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
 
    cout << (solve() ? "YES" : "NO") << endl;
  }
 
}