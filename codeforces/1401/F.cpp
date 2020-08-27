#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;

const int L = 18;
const int N = (2 << L) + 10;
bool rev[L];
bool swp[L];

struct Node {
  int left_child = -1;
  int right_child = -1;
  int level = -1;
  Long sum = 0;
  bool rev = false;
  bool swp = false;
} nodes[N];

int arr[N];

struct SegmentTree {
  int n;
  void build(int node_id, int l, int r, int level) {
    auto& node = nodes[node_id];
    node.level = level;
    if (l == r) {
      node.sum = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    node.left_child = 2 * node_id;
    node.right_child = 2 * node_id + 1;
    build(node.left_child, l, mid, level + 1);
    build(node.right_child, mid + 1, r, level + 1);
    node.sum = nodes[node.left_child].sum + nodes[node.right_child].sum;
  }
  void build(int n) {
    this->n = n;
    build(1, 1, 1 << n, 0);
  }
  void reverse(int k) { rev[n - k] ^= 1; }
  void swap(int k) { swp[n - k - 1] ^= 1; }
  void push(int node_id) {
    auto& node = nodes[node_id];
    if (node.level == n) return;
    auto& left_child = nodes[node.left_child];
    auto& right_child = nodes[node.right_child];
    if (node.rev ^ rev[node.level]) {
      node.rev ^= 1;
      ::swap(node.left_child, node.right_child);
      left_child.rev ^= 1;
      right_child.rev ^= 1;
    }
    if (node.swp ^ swp[node.level]) {
      node.swp ^= 1;
      ::swap(node.left_child, node.right_child);
    }
  }
  Long query(int node_id, int query_l, int query_r, int curr_l, int curr_r) {
    auto& node = nodes[node_id];
    if (curr_l > query_r || curr_r < query_l) return 0;
    if (curr_l >= query_l && curr_r <= query_r) return node.sum;
    push(node_id);
    int mid = (curr_l + curr_r) / 2;
    Long res = query(node.left_child, query_l, query_r, curr_l, mid);
    res += query(node.right_child, query_l, query_r, mid + 1, curr_r);
    return res;
  }
  Long query(int l, int r) { return query(1, l, r, 1, 1 << n); }
  void update(int ind, int value) {
    for (int i = 0; i < 2; ++i) {
      int node_id = 1;
      int l = 1, r = 1 << n;
      while (node_id != -1) {
        push(node_id);
        auto& node = nodes[node_id];
        node.sum += value;
        int mid = (l + r) / 2;
        if (ind <= mid) {
          node_id = node.left_child;
          r = mid;
        } else {
          node_id = node.right_child;
          l = mid + 1;
        }
        if (node_id == -1) {
          value -= node.sum;
        }
      }
    }
  }
} segment_tree;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= (1 << n); ++i) {
    cin >> arr[i];
  }
  segment_tree.build(n);

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, k;
      cin >> x >> k;
      segment_tree.update(x, k);
    }
    if (type == 2) {
      int k;
      cin >> k;
      segment_tree.reverse(k);
    }
    if (type == 3) {
      int k;
      cin >> k;
      segment_tree.swap(k);
    }
    if (type == 4) {
      int l, r;
      cin >> l >> r;
      cout << segment_tree.query(l, r) << endl;
    }
  }
  return 0;
}