#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

struct SegmentTree {
  static const int kSize = 1 << ((int) log2(N) + 2);

  struct Node {
    int left;
    int right;
    int unpaired_pushes;
    int unpaired_pops;
  } nodes[kSize];

  void BuildTree(int node_id = 1, int left = 0, int right = N - 1) {
    Node& node = nodes[node_id];
    node.left = left;
    node.right = right;
    if (left == right) return;
    int mid = (left + right) / 2;
    BuildTree(node_id * 2, left, mid);
    BuildTree(node_id * 2 + 1, mid + 1, right);
  }

  void Update(int ind, bool is_push, int node_id = 1) {
    Node& node = nodes[node_id];
    if (ind < node.left || ind > node.right) return;
    if (node.left == node.right) {
      if (is_push)
        node.unpaired_pushes = 1;
      else
        node.unpaired_pops = 1;
      return;
    }
    Update(ind, is_push, node_id * 2);
    Update(ind, is_push, node_id * 2 + 1);

    Node& left_child = nodes[node_id * 2];
    Node& right_child = nodes[node_id * 2 + 1];

    node.unpaired_pops = left_child.unpaired_pops
      + max(0, right_child.unpaired_pops - left_child.unpaired_pushes);
    node.unpaired_pushes = right_child.unpaired_pushes
      + max(0, left_child.unpaired_pushes - right_child.unpaired_pops);
  }

  int Get(int node_id = 1, int unpaired_pops = 0) {
    Node& node = nodes[node_id];
    if (node.unpaired_pushes == 0) return 0;
    if (node.left == node.right) return node.left;

    Node& left_child = nodes[node_id * 2];
    Node& right_child = nodes[node_id * 2 + 1];

    if (right_child.unpaired_pushes - unpaired_pops > 0) {
      return Get(node_id * 2 + 1, unpaired_pops);
    }
    return Get(node_id * 2,
      right_child.unpaired_pops
        + max(0, unpaired_pops - right_child.unpaired_pushes));
  }

};

int push[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  push[0] = -1;

  int n;
  cin >> n;

  SegmentTree tree;
  tree.BuildTree();

  while (n--) {
    int p, t;
    cin >> p >> t;

    if (t == 1) {
      int x;
      cin >> x;
      push[p] = x;
    }

    tree.Update(p, t == 1);
    cout << push[tree.Get()] << '\n';
  }

}
