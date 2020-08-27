#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif
#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
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
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

static char buf[250 << 20];
static size_t last_size = 0;
static size_t buf_nxt = sizeof buf;

void* operator new(size_t s) {
  last_size = s;
  return (void*)&buf[buf_nxt -= s];
}

void operator delete(void* ptr) {
  if (ptr == ((void*)&buf[buf_nxt])) {
    buf_nxt += last_size;
  }
}

const int N = 1e6 + 5;

int res[N];
int height[N];

vector<int> adj[N];

void build_info(int node, int parent) {
  height[node] = 1;
  for (int v : adj[node]) {
    if (v == parent) continue;
    build_info(v, node);
    height[node] = max(height[node], 1 + height[v]);
  }
}

void merge(const vector<int>& small, vector<int>& big, int node) {
  for (int i = 0; i < sz(small); ++i) {
    int j = i + sz(big) - sz(small);
    big[j] += small[i];
    if (big[j] >= big[res[node]] &&
        (big[j] > big[res[node]] || j > res[node])) {
      res[node] = j;
    }
  }
}

vector<int> solve(int node, int parent) {
  if (height[node] == 1) {
    res[node] = 0;
    return {1};
  }
  int big_child = -1;
  vector<int> d;
  for (int v : adj[node]) {
    if (v == parent) continue;
    if (height[v] == height[node] - 1) {
      big_child = v;
      d = solve(v, node);
      res[node] = res[big_child];
      break;
    }
  }
  for (int v : adj[node]) {
    if (v == parent) continue;
    if (v == big_child) continue;
    auto child_d = solve(v, node);
    merge(child_d, d, node);
  }
  d.emplace_back(1);
  if (d[res[node]] == 1) {
    res[node] = sz(d) - 1;
  }
  return d;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  build_info(1, 0);
  solve(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << height[i] - 1 - res[i] << endl;
  }

  return 0;
}