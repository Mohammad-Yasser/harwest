#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
const int NodesCnt = 2097153;
int arr[N];

struct SegmentTree {
  int nodes[NodesCnt];

  void Update(int node, int a, int b, int ind) {
    if (a > b or a > ind or b < ind) return;

    if (a == b) {
      nodes[node] ^= arr[ind];
      return;
    }

    Update(node * 2, a, (a + b) / 2, ind);
    Update(1 + node * 2, 1 + (a + b) / 2, b, ind);

    nodes[node] = nodes[2 * node] ^ nodes[1 + 2 * node];
  }

  int Query(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i) return {};

    if (a >= i && b <= j) return nodes[node];

    int q1 = Query(node * 2, a, (a + b) / 2, i, j);
    int q2 = Query(1 + node * 2, 1 + (a + b) / 2, b, i, j);

    return q1 ^ q2;
  }

} tree;
int nxt[N];

vector<pair<int, int> > queries[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  unordered_map<int, int> last;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    auto it = last.find(arr[i]);
    if (it == last.end()) {
      last[arr[i]] = i;
    } else {
      nxt[it->second] = i;
      tree.Update(1, 0, n - 1, i);
      it->second = i;
    }
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    queries[l].push_back({r, i});
  }

  for (int i = 0; i < n; ++i) {
    for (auto q : queries[i])
      ans[q.second] = tree.Query(1, 0, n - 1, i, q.first);
    if (nxt[i]) tree.Update(1, 0, n - 1, nxt[i]);
  }

  for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}
