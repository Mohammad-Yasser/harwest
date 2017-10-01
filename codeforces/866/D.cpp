#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 3e5 + 5;
const int OO = 1e7;

struct Node {
  pair<int, int> mn = { OO, -1 };
  pair<int, int> mx = { 0, -1 };

  int sum = 0;
  int min_prefix = 0;
  int l, r;
};

int arr[N];

struct SegmentTree {
  constexpr static int Size = 4 * N;

  Node nodes[Size];

  void updateNode(int node_id) {
    auto& node = nodes[node_id];

    auto& left_child = nodes[node_id * 2];
    auto& right_child = nodes[node_id * 2 + 1];

    node.mn = min(left_child.mn, right_child.mn);
    node.mx = max(left_child.mx, right_child.mx);
    node.sum = left_child.sum + right_child.sum;
    node.min_prefix = min(left_child.min_prefix,
      right_child.min_prefix + left_child.sum);
  }

  void build(int node_id, int l, int r) {
    auto& node = nodes[node_id];
    node.l = l;
    node.r = r;

    if (l == r) {
      node.mn = node.mx = {arr[l] , l};
      return;
    }

    int mid = (l + r) / 2;
    build(node_id * 2, l, mid);
    build(node_id * 2 + 1, mid + 1, r);

    updateNode(node_id);
  }

  pair<int, int> getMin(int node_id, int l, int r) {
    auto& node = nodes[node_id];
    if (node.l > r || node.r < l) return {OO, -1};
    if (node.l >= l && node.r <= r) return node.mn;

    return min(getMin(node_id * 2, l, r), getMin(node_id * 2 + 1, l, r));
  }

  int getLastAvailable(int node_id, int prev_sum = 0) {
    auto& node = nodes[node_id];
    if (node.min_prefix + prev_sum >= 0) return node.r;
    if (node.l == node.r) return node.l - 1;

    auto& left_child = nodes[node_id * 2];
    auto& right_child = nodes[node_id * 2 + 1];

    if (prev_sum + left_child.min_prefix < 0)
      return getLastAvailable(node_id * 2, prev_sum);
    return getLastAvailable(node_id * 2 + 1, prev_sum + left_child.sum);
  }

  void update(int node_id, int removed, int val) {
    auto& node = nodes[node_id];
    if (node.l > removed || node.r < removed) return;
    if (node.l == node.r) {
      node.mn = {OO , - 1};
      node.mx = {0 , -1};
      node.sum = val;
      node.min_prefix = val;
      return;
    }
    update(node_id * 2, removed, val);
    update(node_id * 2 + 1, removed, val);

    updateNode(node_id);
  }

} tree;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  tree.build(1, 1, n);

  Long res = 0;
  while (tree.nodes[1].mx.second != -1) {
    int mx = tree.nodes[1].mx.second;

    tree.update(1, mx, -1);

    int last_available = tree.getLastAvailable(1, 0);
    int mn = tree.getMin(1, 1, last_available).second;

    if (mn == -1 || arr[mn] > arr[mx]) {
      tree.update(1, mx, 0);
      continue;
    }

    res += arr[mx] - arr[mn];
    tree.update(1, mn, 1);

  }

  cout << res;

}
