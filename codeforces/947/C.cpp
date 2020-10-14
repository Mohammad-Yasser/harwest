#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rep(i, l, r) for (int i = l; i < r; ++i)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int TrieSize = 30 * 300000;
const int B = 30;
struct Node {
  static int getNewNode() {
    static int nextNodeId = 1;
    assert(nextNodeId + 1 < TrieSize);
    return nextNodeId++;
  }
  static const int DummyNode = 0;
  int cnt = 0;
  int children[2] = {DummyNode, DummyNode};
  int getChild(int ind, bool create_if_not_exist = true) {
    if (children[ind] == DummyNode) {
      if (create_if_not_exist) return children[ind] = getNewNode();
      return DummyNode;
    }
    return children[ind];
  }
} nodes[TrieSize];

struct Trie {
  int root_id = Node::getNewNode();

  void add(int x, int val) {
    int curr = root_id;
    nodes[curr].cnt += val;
    for (int i = B - 1; i >= 0; --i) {
      bool b = (x >> i) & 1;
      curr = nodes[curr].getChild(b);
      nodes[curr].cnt += val;
    }
  }
  int query(int x) {
    int curr = root_id;
    int res = 0;
    --nodes[curr].cnt;
    for (int i = B - 1; i >= 0; --i) {
      bool b = (x >> i) & 1;
      if (nodes[nodes[curr].getChild(b)].cnt > 0) {
        curr = nodes[curr].getChild(b);
      } else {
        res |= (1 << i);
        curr = nodes[curr].getChild(!b);
      }
      --nodes[curr].cnt;
    }

    return res;
  }

} trie;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  vector<int> a(n), p(n);
  cin >> a >> p;
  for (int x : p) {
    trie.add(x, 1);
  }
  for (int x : a) {
    cout << trie.query(x) << " ";
  }
  cout << endl;

  return 0;
}