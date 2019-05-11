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

const int A = 'z' - 'a' + 1;
const int N = 1e5 + 5;

struct Node {
  int start = -1, end = -1; // The node covers the range [start,end].

  int sum = 0;
  int mxIndex = -1;
  int lazy = -1;

  static Node merge(const Node& a, const Node& b) {
    Node res;
    res.start = a.start;
    res.end = b.end;

    res.sum = a.sum + b.sum;
    res.mxIndex = max(a.mxIndex, b.mxIndex);

    return res;
  }

  bool inRange(int x) const {
    return start <= x && x <= end;
  }

  void updateLazy() {
    if (lazy == -1) return;
    sum = lazy * (end - start + 1);
    if (lazy == 0) {
      mxIndex = -1;
    } else {
      mxIndex = end + lazy - 1;
    }
    lazy = -1;
  }

  void print() const {
    cout << "Node: " << start << " " << end << " " << sum << " " << mxIndex
      << " " << lazy << endl;
  }
};

struct SegmentTree {
  static const int kSize = 1 << int(log2(N) + 2);

  vector<Node> nodes;

  void build(int node_id, int left, int right) {
    Node& node = nodes[node_id];
    node.start = left, node.end = right;
    if (left == right) {
      node.sum = 0;
      node.mxIndex = -1;
      return;
    }

    int mid = (left + right) / 2;
    build(node_id * 2, left, mid);
    build(node_id * 2 + 1, mid + 1, right);
    node = Node::merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }

  void build(int n) {
    nodes.resize(kSize);
    build(1, 0, n - 1);
  }

  void print() {
    for (int i = 0; i < kSize; ++i) {
      auto& node = nodes[i];
      if (node.start == -1) continue;
      pushLazy(i);
      cout << i << endl;
      node.print();
    }
  }

  void updateLazy(int node_id) {
    Node& node = nodes[node_id];
    node.updateLazy();
  }

  void pushLazy(int node_id) {
    Node& node = nodes[node_id];
    if (node.lazy == -1) return;
    if (node.start != node.end) {
      nodes[node_id * 2].lazy = nodes[node_id * 2 + 1].lazy = node.lazy;
    }
    node.updateLazy();
  }

  void update(int node_id, int l, int r, int val) {
    auto& node = nodes[node_id];
    pushLazy(node_id);

    if (max(node.mxIndex, node.end) < l || node.start > r) {
      return;
    }

    if (l <= node.start && node.end <= r) {
      int tmp = node.mxIndex;

      node.lazy = val;
      pushLazy(node_id);

      if (tmp > r) {
        update(r + 1, r + 1, tmp - r);
      }

      return;
    }

    if (node.start == node.end) {
      assert(node.end < l && val == 0);
      int tmp = node.mxIndex;

      node.mxIndex = l - 1;
      node.sum = node.mxIndex - node.start + 1;
      node.lazy = -1;

      if (tmp > r) {
        update(r + 1, r + 1, tmp - r);
      }

      return;
    }

    update(node_id * 2, l, r, val);
    update(node_id * 2 + 1, l, r, val);
    node = Node::merge(nodes[node_id * 2], nodes[node_id * 2 + 1]);
  }

  int query(int node_id, int l, int r) {
    auto& node = nodes[node_id];
    pushLazy(node_id);
    if (node.mxIndex < l || node.start > r) {
      return 0;
    }

    if (node.end < l) {
      return min(r, node.mxIndex) - l + 1;
    }

    if (l <= node.start && node.mxIndex <= r) {
      return node.sum;
    }

    if (node.start == node.end) {
      if (node.mxIndex == -1) return 0;
      return min(r, node.mxIndex) - node.start + 1;
    }

    int res = 0;
    res += query(node_id * 2, l, r);
    res += query(node_id * 2 + 1, l, r);

    return res;
  }

  int query(int l, int r) {
    int res = query(1, l, r);
    return res;
  }

  void update(int l, int r, int val) {
    update(1, l, r, val);
  }

} seg_trees[A];

int n, q;
string s;

vector<tuple<int, int, int>> queries;

string solveO() {
  for (int i = 0; i < A; ++i) {
    seg_trees[i].build(n);
  }

  for (int i = 0; i < n; ++i) {
    seg_trees[s[i] - 'a'].update(i, i, 1);
  }

  for (auto& query : queries) {
    int l, r, k;
    tie(l, r, k) = query;
    --l, --r;

    vector<int> cnt(A, 0);
    for (int i = 0; i < A; ++i) {
      cnt[i] = seg_trees[i].query(l, r);
    }

    if (k == 0) {
      int last = r;
      for (int i = 0; i < A; ++i) {
        if (cnt[i] == 0) continue;
        last -= cnt[i] - 1;
        seg_trees[i].update(l, r, 0);
        seg_trees[i].update(last, last, cnt[i]);
        --last;
      }
    } else {
      int last = l;
      for (int i = 0; i < A; ++i) {
        if (cnt[i] == 0) continue;
        seg_trees[i].update(l, r, 0);
        seg_trees[i].update(last, last, cnt[i]);
        last += cnt[i];
      }
    }
  }


  string res(n, 0);

  for (int i = 0; i < n; ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (seg_trees[c - 'a'].query(i, i) == 1) {
        res[i] = c;
      }
    }
  }
  return res;
}

string solveBt() {
  string res = s;
  for (auto& query : queries) {
    int l, r, k;
    tie(l, r, k) = query;
    --l, --r;

    if (k == 0) {
      sort(res.begin() + l, res.begin() + r + 1, greater<char>());
    } else {
      sort(res.begin() + l, res.begin() + r + 1);
    }
  }

  return res;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int q;
  cin >> n >> q;
  cin >> s;
  queries.resize(q);
  for (auto& query : queries) {
    int l, r, k;
    cin >> l >> r >> k;
    query = tie(l, r, k);
  }

  cout << solveO() << endl;
}
