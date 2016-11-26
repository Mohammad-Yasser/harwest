#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300005;

ll arr[N];
int n;

#define print(x) cout << #x << " = " << x << endl

struct SegmentTree {
  struct Node {
    int ans = 0;
    int leftmost_type = 0, leftmost_size = 0;
    int rightmost_type = 0, rightmost_size = 0;
    int total_size = 0;
    int left = -1, right = -1;
  };

  void PrintNode(Node node) {
    cout << "___________________________________" << endl;
    print(node.left);
    print(node.right);
    print(node.ans);
    print(node.leftmost_type);
    print(node.leftmost_size);
    print(node.rightmost_type);
    print(node.rightmost_size);
    print(node.total_size);
    cout << "___________________________________" << endl;
  }

  void Print() {
    for (int i = 2 * n - 1; i > 0; --i) {
      cout << i << endl;
      PrintNode(nodes[i]);
    }
  }

  Node nodes[2 * N];

  Node Merge(Node left, Node right) {
    if (left.left == -1) {
      return right;
    }
    if (right.left == -1) {
      return left;
    }
    if (left.left > right.right) {
      swap(left, right);
    }
    Node node;
    node.ans = max(left.ans, right.ans);
    bool can = (left.rightmost_type == 1
      || (left.rightmost_type == -1 && right.leftmost_type == -1));
    if (can) {
      node.ans = max(node.ans, left.rightmost_size + right.leftmost_size);
    }

    node.leftmost_type = left.leftmost_type;
    node.leftmost_size = left.leftmost_size;
    if (left.leftmost_size == left.total_size && can) {
      node.leftmost_size += right.leftmost_size;
    }

    node.rightmost_type = right.rightmost_type;
    node.rightmost_size = right.rightmost_size;
    if (right.rightmost_size == right.total_size && can) {
      node.rightmost_size += left.rightmost_size;
    }

    node.total_size = left.total_size + right.total_size;
    node.left = left.left;
    node.right = right.right;
    return node;
  }

  Node MakeLeaf(int pos) {
    Node leaf;
    leaf.total_size = 1;
    leaf.left = leaf.right = pos;

    if (arr[pos] > 0) {
      leaf.ans = 1;
      leaf.leftmost_type = leaf.rightmost_type = 1;
      leaf.leftmost_size = leaf.rightmost_size = 1;
    }

    if (arr[pos] < 0) {
      leaf.ans = 1;
      leaf.leftmost_type = leaf.rightmost_type = -1;
      leaf.leftmost_size = leaf.rightmost_size = 1;
    }

    return leaf;
  }

  void Build() {
    for (int i = n; i < 2 * n; ++i) {
      nodes[i] = MakeLeaf(i - n);
    }
    for (int i = n - 1; i > 0; --i) {
      nodes[i] = Merge(nodes[i << 1], nodes[(i << 1) | 1]);
    }
  }

  void Update(int pos, int value) {
    arr[pos] += value;
    nodes[pos + n] = MakeLeaf(pos);
    for (pos += n; pos > 1; pos >>= 1) {
      nodes[pos >> 1] = Merge(nodes[pos], nodes[pos ^ 1]);
    }
  }

  Node Query(int l, int r) {
    Node res_left, res_right;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res_left = Merge(res_left, nodes[l++]);
      if (r & 1) res_right = Merge(nodes[--r], res_right);
    }
    return Merge(res_left, res_right);
  }

} tree;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  --n;
  for (int i = 0; i < n; ++i) {
    arr[i] = arr[i + 1] - arr[i];
  }

  tree.Build();

//  tree.Print();
//  cout << tree.nodes[1].ans + 1 << endl;

  int m;
  cin >> m;
  while (m--) {
    int l, r, d;
    cin >> l >> r >> d;
    --l, --r;
    if (l > 0) {
      tree.Update(l - 1, d);
    }
    if (r < n) {
      tree.Update(r, -d);
    }
//    tree.Print();
    cout << tree.Query(0, n).ans + 1 << '\n';
  }
  return 0;
}