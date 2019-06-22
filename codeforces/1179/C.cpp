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

const int N = 1e6 + 7;

int dishes[N];
int pupils[N];

struct Node {
  int start, end; // The node covers the range [start,end].

  int max_suffix_sum = 0;
  int lazy = 0;

  static Node merge(const Node& a, const Node& b) {
    Node res;
    res.start = a.start;
    res.end = b.end;

    res.max_suffix_sum = max(a.max_suffix_sum, b.max_suffix_sum);

    return res;
  }

  bool inRange(int x) const {
    return start <= x && x <= end;
  }

  void print() const {
    cout << start << " " << end << " " << max_suffix_sum << " " << lazy << endl;
  }
};

struct SegmentTree {
  static const int kSize = 1 << int(log2(N) + 2);

  array<Node, kSize> nodes;

  void build(int node_id, int left, int right) {
    Node& node = nodes[node_id];
    node.start = left, node.end = right;
    if (left == right) return;

    int mid = (left + right) / 2;
    build(node_id * 2, left, mid);
    build(node_id * 2 + 1, mid + 1, right);
    node = Node::merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }

  void build() {
    build(1, 0, N - 1);
  }

  void push(int node_id) {
    auto& node = nodes[node_id];
    node.max_suffix_sum += node.lazy;
    if (node.start != node.end) {
      nodes[node_id * 2].lazy += node.lazy;
      nodes[node_id * 2 + 1].lazy += node.lazy;
    }
    node.lazy = 0;
  }

  void update(int node_id, int r, int val) {
    push(node_id);
    auto& node = nodes[node_id];
    if (node.start > r) return;
    if (node.end <= r) {
      node.lazy += val;
      push(node_id);
      return;
    }
    update(node_id * 2, r, val);
    update(node_id * 2 + 1, r, val);
    node = Node::merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }

  int query(int node_id) {
    auto& node = nodes[node_id];
    if (node.start == node.end) return node.start;

    push(node_id * 2 + 1);
    if (nodes[node_id * 2 + 1].max_suffix_sum > 0) {
      return query(node_id * 2 + 1);
    }

    push(node_id * 2);
    if (nodes[node_id * 1].max_suffix_sum > 0) {
      return query(node_id * 2);
    }
    assert(node_id == 1);
    return -1;
  }

} seg_tree;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;
  cin >> n >> m;

  seg_tree.build();

  for (int i = 1; i <= n; ++i) {
    cin >> dishes[i];
    seg_tree.update(1, dishes[i], 1);
  }

  for (int i = 1; i <= m; ++i) {
    cin >> pupils[i];
    seg_tree.update(1, pupils[i], -1);
  }

  int q;
  cin >> q;

  while (q--) {
    int type, i, x;
    cin >> type >> i >> x;
    if (type == 1) {
      seg_tree.update(1, dishes[i], -1);
      dishes[i] = x;
      seg_tree.update(1, dishes[i], 1);
    } else {
      seg_tree.update(1, pupils[i], 1);
      pupils[i] = x;
      seg_tree.update(1, pupils[i], -1);
    }
    cout << seg_tree.query(1) << endl;
  }

}
