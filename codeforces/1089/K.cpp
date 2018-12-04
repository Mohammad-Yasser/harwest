#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

constexpr int N = 1e6 + 5;

struct Node {
  int start, end; // The node covers the range [start,end].

  // The node is responsible only for the events with 't' in its range.
  Long overflow = 0;
  Long occupied = 0;

  int getSize() const {
    return end - start + 1;
  }

  bool inRange(int x) const {
    return start <= x && x <= end;
  }

  Long getTotal() const {
    return occupied + overflow;
  }

  static Node merge(const Node& a, const Node& b) {
    Node res;
    res.start = a.start;
    res.end = b.end;

    res.overflow = b.overflow;

    Long b_occupied = a.overflow + b.occupied;
    res.overflow += max(0LL, b_occupied - b.getSize());

    res.occupied = a.getTotal() + b.getTotal() - res.overflow;

    return res;
  }

  void print() const {
    cout << start << " " << end << " " << occupied << " " << overflow << endl;
  }
};

struct SegmentTree {
  static const int kSize = 1 << int(log2(N) + 2);

  Node nodes[kSize];

  void build(int node_id, int left, int right) {
    Node& node = nodes[node_id];
    node.start = left, node.end = right;
    if (left == right) return;

    int mid = (left + right) / 2;
    build(node_id * 2, left, mid);
    build(node_id * 2 + 1, mid + 1, right);
  }

  void update(int node_id, int t, int k) {
    auto& node = nodes[node_id];
    if (!node.inRange(t)) return;
    if (node.start == node.end) {
      node.overflow = k;
      return;
    }
    update(node_id * 2, t, k);
    update(node_id * 2 + 1, t, k);
    node = Node::merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }

  Node query(int node_id, int t) {
    auto& node = nodes[node_id];
    if (node.end <= t) return node;
    Node a = query(node_id * 2, t);
    if (a.end >= t) {
      return a;
    }
    Node b = query(node_id * 2 + 1, t);
    Node res = Node::merge(a, b);
    return res;
  }

} tree;

int events[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  tree.build(1, 0, N - 1);

  int q;
  cin >> q;

  for (int i = 1; i <= q; ++i) {
    char c;
    cin >> c;

    if (c == '+') {
      int t, k;
      cin >> t >> k;
      tree.update(1, t - 1, k);
      events[i] = t;
    }

    if (c == '-') {
      int idx;
      cin >> idx;
      tree.update(1, events[idx] - 1, 0);
    }

    if (c == '?') {
      int t;
      cin >> t;
      cout << tree.query(1, t - 1).overflow << endl;
    }
  }

}
