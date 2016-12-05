#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int Q = 200005;

struct SegmentTree {
  int n;
  int nodes[2 * N];

  void Build() {
    memset(nodes, 0, sizeof nodes);
  }

  void Update(int p, int value) {
    p += n;
    nodes[p] = value;
    for (; p > 1; p >>= 1)
      nodes[p >> 1] = min(nodes[p], nodes[p ^ 1]);
  }

  int Query(int l, int r) {
    ++r;
    int res = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min(res, nodes[l++]);
      if (r & 1) res = min(res, nodes[--r]);
    }
    return res;
  }
};

struct Rectangle {
  int x1, x2, y1, y2;

  bool ans = false;
} rectangles[Q];

vector<int> rows_queries[Q];
vector<int> col_queries[Q];

vector<int> rooks_in_row[N]; // The columns of rooks in each row.
vector<int> rooks_in_col[N];

void Solve(int n, int m, const vector<int> queries[Q],
  const vector<int> rooks[N]) {
  SegmentTree tree;
  tree.n = m + 1;
  tree.Build();

  for (int i = 1; i <= n; ++i) {
    for (int rook : rooks[i]) {
      tree.Update(rook, i);
    }
    for (int q : queries[i]) {
      auto &rect = rectangles[q];
      int min_col = tree.Query(rect.y1, rect.y2);
      rect.ans |= (min_col >= rect.x1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif

  int n, m, k, q;
  cin >> n >> m >> k >> q;

  while (k--) {
    int x, y;
    cin >> x >> y;
    rooks_in_row[y].push_back(x);
    rooks_in_col[x].push_back(y);
  }

  for (int i = 0; i < q; ++i) {
    cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2
      >> rectangles[i].y2;
    rows_queries[rectangles[i].y2].push_back(i);
    col_queries[rectangles[i].x2].push_back(i);
  }

  Solve(n, m, col_queries, rooks_in_col);
  for (int i = 0; i < q; ++i) {
    auto &rect = rectangles[i];

    swap(rect.x1, rect.y1);
    swap(rect.x2, rect.y2);
  }
  Solve(m, n, rows_queries, rooks_in_row);

  for (int i = 0; i < q; ++i) {
    cout << (rectangles[i].ans ? "YES\n" : "NO\n");
  }
  return 0;
}
