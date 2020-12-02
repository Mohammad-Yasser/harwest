#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
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

const int N = 1e6 + 5;
char ans[N];

struct Node {
  char type;
  vector<int> children;  // inputs will be stored here too.
  bool res;              // if nothing changes.
  Node() : children(0) {}
} nodes[N];

bool build(int node_id) {
  auto& node = nodes[node_id];
  if (node.type == 'I') {
    return node.res = node.children[0];
  }
  for (int v : node.children) {
    build(v);
  }
  if (node.type == 'X') {
    return node.res =
               (nodes[node.children[0]].res ^ nodes[node.children[1]].res);
  }
  if (node.type == 'A') {
    return node.res =
               (nodes[node.children[0]].res & nodes[node.children[1]].res);
  }
  if (node.type == 'O') {
    return node.res =
               (nodes[node.children[0]].res | nodes[node.children[1]].res);
  }
  if (node.type == 'N') {
    return node.res = !nodes[node.children[0]].res;
  }
}

enum State : char { ALWAYS_TRUE, ALWAYS_FALSE, SAME, OPPOSITE };

bool f(State state, bool input) {
  if (state == ALWAYS_TRUE) return true;
  if (state == ALWAYS_FALSE) return false;
  if (state == SAME) return input;
  return !input;
}

void solve(int node_id, State state) {
  vector<pair<int, State>> st;
  st.reserve(N);
  st.emplace_back(1, SAME);
  while (!st.empty()) {
    auto [node_id, state] = st.back();
    auto& node = nodes[node_id];
    st.pop_back();
    if (node.type == 'I') {
      ans[node_id] = f(state, !node.res);
      continue;
    }
    if (state < 2) {
      for (int v : node.children) {
        st.emplace_back(v, state);
      }
      continue;
    }
    if (node.type == 'A') {
      for (int i = 0; i < 2; ++i) {
        if (nodes[node.children[i]].res) {
          st.emplace_back(node.children[i ^ 1], state);
        } else {
          st.emplace_back(node.children[i ^ 1],
                          (state == SAME ? ALWAYS_FALSE : ALWAYS_TRUE));
        }
      }
    }

    if (node.type == 'O') {
      for (int i = 0; i < 2; ++i) {
        if (!nodes[node.children[i]].res) {
          st.emplace_back(node.children[i ^ 1], state);
        } else {
          st.emplace_back(node.children[i ^ 1],
                          (state == SAME ? ALWAYS_TRUE : ALWAYS_FALSE));
        }
      }
    }

    if (node.type == 'X') {
      for (int i = 0; i < 2; ++i) {
        st.emplace_back(node.children[i ^ 1],
                        State(state ^ nodes[node.children[i]].res));
      }
    }

    if (node.type == 'N') {
      st.emplace_back(node.children[0], State(state ^ 1));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#define endl '\n'
#endif
  memset(ans, -1, sizeof ans);
  int n;
  cin >> n;
  string tmp;
  for (int i = 1; i <= n; ++i) {
    cin >> tmp;
    nodes[i].type = tmp[0];
    if (nodes[i].type == 'I' || nodes[i].type == 'N') {
      nodes[i].children.resize(1);
    } else {
      nodes[i].children.resize(2);
    }
    cin >> nodes[i].children;
  }
  build(1);
  solve(1, SAME);
  for (int i = 1; i <= n; ++i) {
    if (ans[i] != -1) {
      cout << (ans[i] == 1);
    }
  }
  cout << endl;
  return 0;
}