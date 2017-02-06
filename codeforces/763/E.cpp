#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;

struct DSU {
  vector<int> parent[3];
  vector<int> size[3];
  int start[3];

  int cnt_sets;
  int left;
  int right;

  DSU() {
  }

  int& GetParentOrSize(int x, bool is_parent = true) {
    for (int i = 0; i < 3; ++i) {
      if (x - start[i] < parent[i].size()) {
        if (is_parent)
          return parent[i][x - start[i]];
        else
          return size[i][x - start[i]];
      }
    }
  }

  void AssignParent(DSU& dsu) {
    for (int i = dsu.left; i <= min(dsu.right, dsu.left + 4); ++i) {
      int p = dsu.GetRoot(i);

      if (p >= dsu.left + 5 && p <= dsu.right - 5) {
        dsu.GetParentOrSize(p) = i;
        dsu.GetParentOrSize(i) = i;
        p = i;
      }

      GetParentOrSize(i) = p;
      GetParentOrSize(i, false) = dsu.GetParentOrSize(i, false);
    }

    for (int i = max(dsu.right - 4, dsu.left); i <= dsu.right; ++i) {
      int p = dsu.GetRoot(i);

      if (p >= dsu.left + 5 && p <= dsu.right - 5) {
        dsu.GetParentOrSize(p) = i;
        dsu.GetParentOrSize(i) = i;
        p = i;
      }

      GetParentOrSize(i) = p;
      GetParentOrSize(i, false) = dsu.GetParentOrSize(i, false);
    }
  }

  DSU(DSU& dsu_left, DSU& dsu_right) {
    cnt_sets = dsu_left.cnt_sets + dsu_right.cnt_sets;

    left = dsu_left.left;
    right = dsu_right.right;

    start[0] = left;
    parent[0].resize(5);
    size[0].resize(5);

    start[1] = dsu_left.right - 4;
    parent[1].resize(10);
    size[1].resize(10);

    start[2] = right - 4;
    parent[2].resize(5);
    size[2].resize(5);

    AssignParent(dsu_left);
    AssignParent(dsu_right);
  }

  DSU(int x) :
    left(x), right(x) {

    start[0] = x;

    parent[0].resize(1);
    parent[0][0] = x;

    size[0].resize(1);
    size[0][0] = 1;

    cnt_sets = 1;
  }

  int GetRoot(int node) {
    if (GetParentOrSize(node) == node) {
      return node;
    }
    return GetParentOrSize(node) = GetRoot(GetParentOrSize(node));
  }

  void Join(int x, int y) {
    x = GetRoot(x);
    y = GetRoot(y);

    if (x == y) return;
    --cnt_sets;

    if (GetParentOrSize(x, false) > GetParentOrSize(y, false)) {
      swap(x, y);
    }
    GetParentOrSize(x) = y;
    GetParentOrSize(y, false) += GetParentOrSize(x, false);
  }
};

int n;

vector<int> adj[N];

struct SegmentTree {
  static const int size = 1 << (int) ((ceil(log2(N + 1e-9))) + 1);
  struct Node {
    int left = 0;
    int right = 0;

    DSU dsu;
  };

  vector<Node> nodes;

  SegmentTree() {
    nodes.resize(size);
  }

  Node Merge(Node& left, Node& right) {
    if (left.right == 0) {
      return right;
    }
    if (right.right == 0) {
      return left;
    }

    Node node;
    node.left = left.left;
    node.right = right.right;
    node.dsu = DSU(left.dsu, right.dsu);

    for (int u = max(node.left, right.left - 5); u < right.left; ++u) {
      for (int v : adj[u]) {
        if (v > node.right) continue;
        node.dsu.Join(u, v);
      }
    }

    return node;
  }

  void Build(int node_id = 1, int left = 1, int right = n) {
    Node& node = nodes[node_id];

    if (left == right) {
      node.dsu = DSU(left);
      node.left = node.right = left;
      return;
    }

    int mid = (left + right) / 2;
    Build(node_id * 2, left, mid);
    Build(node_id * 2 + 1, mid + 1, right);

    node = Merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }

  Node Query(int left, int right, int node_id = 1) {
    Node& node = nodes[node_id];
    if (right < node.left || node.right < left) {
      return Node();
    }
    if (left <= node.left && node.right <= right) {
      return node;
    }

    Node left_node = Query(left, right, node_id * 2);
    Node right_node = Query(left, right, node_id * 2 + 1);

    return Merge(left_node, right_node);
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n;
  int k;
  cin >> k;

  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    adj[u].push_back(v);
  }

  SegmentTree segment_tree;
  segment_tree.Build();
  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;

    auto node = segment_tree.Query(l, r);
    cout << node.dsu.cnt_sets << '\n';
  }
}
